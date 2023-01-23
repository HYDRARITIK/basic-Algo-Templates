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

TreeNode *build(int pre_start, int pre_end, int in_start, int in_end, vector<int> preorder, vector<int> inorder)
{

    if (in_start > in_end)
        return nullptr;

    int node_idx = in_start;

    while (inorder[node_idx] != preorder[pre_start])
    {
        node_idx++;
    }
    int count_of_leftSubtreeNodes = node_idx - in_start;

    TreeNode *nn=new TreeNode(preorder[pre_start]);
   
    TreeNode *left_subtree = build(pre_start +1, pre_start + count_of_leftSubtreeNodes, in_start, node_idx - 1, preorder, inorder);
    TreeNode *right_subtree = build(pre_start + count_of_leftSubtreeNodes+1, pre_end, node_idx + 1, in_end, preorder, inorder);
    
    nn->left = left_subtree;
    nn->right = right_subtree;

    return nn;
}

TreeNode *buildTree(vector<int> preorder, vector<int> inorder)
{
    int n=preorder.size();

    return build(0,n-1,0,n-1,preorder,inorder);
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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}