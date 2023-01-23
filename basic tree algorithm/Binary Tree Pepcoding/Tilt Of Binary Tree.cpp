//
// Created by anubhav on 4/13/2021.
//
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(int *arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        // pair<Node*,int> pe=st.top();
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }

            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = " <- " + to_string(node->data) + " -> ";

    string left = (node->left == nullptr) ? "." : "" + to_string(node->left->data);
    string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

    str = left + str + right;
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int tilt=0;

int returnSumCalcTilt(Node *root){
    if(root==nullptr){
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr){
        return root->data;
    }

    

    int left_sum=returnSumCalcTilt(root->left);
    int right_sum=returnSumCalcTilt(root->right);
    tilt+=left_sum-right_sum;

    return left_sum+right_sum+root->data;
}

int main()
{
    // 19
    // 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1


    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
       cin>>v[i];
    }
   
    Node *root = construct(v);
    cout<<returnSumCalcTilt(root);
    // display(root);
}