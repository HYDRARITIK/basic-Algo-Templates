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

int min_node_sofar=INT_MAX;
int max_node_sofar=INT_MIN;


class mmPair{
    public:
    int min_node_sofar;
    int max_node_sofar;
    int size;
    bool IsBst;
    mmPair(int  a=INT16_MAX,int b =INT16_MIN){
        this->min_node_sofar=a;
        this->size=0;
         this-> max_node_sofar=b;
         IsBst=true;
    }
};


int max_upper_node;
int size_so_far=0;



mmPair isTreeBst(Node *root)
{

    if(root==nullptr){
        mmPair kk;
        return kk;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        mmPair kk;
        kk.max_node_sofar=root->data;
        kk.min_node_sofar=root->data;
        kk.size=1;
        kk.IsBst=true;
        return kk;
    }


    mmPair isLeft = isTreeBst(root->left);
    mmPair isRight = isTreeBst(root->right);

    mmPair nn;
    nn.min_node_sofar=min(root->data,min(isLeft.min_node_sofar,isRight.min_node_sofar) );
    nn.max_node_sofar=max(root->data,max(isRight.max_node_sofar,isLeft.max_node_sofar)  );

    nn.IsBst= isLeft.IsBst && isRight.IsBst && (root->data >isLeft.max_node_sofar && root->data < isRight.min_node_sofar );

    nn.size=isLeft.size+isRight.size+1;

    if(nn.IsBst){
        if(nn.size >size_so_far){
            size_so_far=nn.size;
            max_upper_node=root->data;
        }
    }

    return nn;
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
        cin >> v[i];
    }

    Node *root = construct(v);
    isTreeBst(root);

    cout<<max_upper_node<<" @ "<<size_so_far;
    // display(root);
}