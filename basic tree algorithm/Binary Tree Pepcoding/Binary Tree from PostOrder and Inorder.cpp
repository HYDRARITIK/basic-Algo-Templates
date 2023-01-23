#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val ;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->left=nullptr;
        this->right=nullptr;
        this->val = val;
    }
};

TreeNode *build(int post_start, int post_end, int in_start, int in_end, vector<int> postorder, vector<int> inorder)
{

    if (in_start > in_end)
        return nullptr;

    int node_idx = in_start;

    while (inorder[node_idx] != postorder[post_end])
    {
        node_idx++;
    }
    int count_of_rightSubtreeNodes = node_idx-in_start;

    TreeNode *nn=new TreeNode(postorder[post_end]);
   
    TreeNode *left_subtree = build(post_start , post_start+count_of_rightSubtreeNodes-1, in_start, node_idx - 1, postorder, inorder);
    TreeNode *right_subtree = build(post_start+count_of_rightSubtreeNodes,post_end-1, node_idx + 1, in_end, postorder, inorder);
    
    nn->left = left_subtree;
    nn->right = right_subtree;

    return nn;
}

TreeNode *buildTree(vector<int> postorder, vector<int> inorder)
{
    int n=postorder.size();

    return build(0,n-1,0,n-1,postorder,inorder);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}



void solve()
{
    int n;
    cin >> n;
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(post, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}