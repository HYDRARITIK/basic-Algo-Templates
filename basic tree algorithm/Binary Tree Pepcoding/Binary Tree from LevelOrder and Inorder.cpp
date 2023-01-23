#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->val = val;
    }
};

template <typename T>
vector<T> slicing(vector<T> const &v,
                  int X, int Y)
{

    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;

    // Copy the element
    vector<T> vector(first, last);

    // Return the results
    return vector;
}

TreeNode *build(int in_start, int in_end, vector<int> levelorder, vector<int> inorder)
{

    if (in_start > in_end)
        return nullptr;

    TreeNode *nn = new TreeNode(levelorder[0]);
    if (levelorder.size() == 1)
        return nn;
    int node_idx = in_start;

    while (inorder[node_idx] != levelorder[0])
    {
        node_idx++;
    }
    int count_of_leftSubtreeNodes = node_idx - in_start;

    map<int, int> mp_left_subtree;

    for (int i = in_start; i < node_idx; i++)
    {
        mp_left_subtree[inorder[i]]++;
    }

    vector<int> left_arr;
    vector<int> right_arr;

    for (int i = 1; i < levelorder.size(); i++)
    {
      
        if ( mp_left_subtree.size()!=0 && mp_left_subtree[levelorder[i]])
        {
            left_arr.push_back(levelorder[i]);
            mp_left_subtree.erase(levelorder[i]);
        }
        else
        {
            right_arr.push_back(levelorder[i]);
        }
    }


    TreeNode *left_subtree = build(in_start, node_idx - 1, left_arr, inorder);
    TreeNode *right_subtree = build(node_idx + 1, in_end, right_arr, inorder);

    nn->left = left_subtree;
    nn->right = right_subtree;

    return nn;
}

TreeNode *buildTree(vector<int> levelorder, vector<int> inorder)
{
    int n = levelorder.size();

    return build(0, n - 1, levelorder, inorder);
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
    vector<int> level(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(level, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}