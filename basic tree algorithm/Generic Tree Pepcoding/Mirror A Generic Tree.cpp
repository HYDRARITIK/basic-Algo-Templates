#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *construct(int *arr, int n)
{
    Node *root = new Node();
    root->data = arr[0];
    stack<Node *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *nn = new Node();
            nn->data = arr[i];
            st.top()->children.push_back(nn);
            st.push(nn);
        }
    }
    return root;
}
void display(Node *root)
{
    cout << root->data << " -> ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << "." << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}

void mirrorTree(Node *root)
{
    cout << root->data << " -> ";
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << "." << endl;
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        mirrorTree(root->children[i]);
    }
}

int main()
{
//     12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    display(root);
    cout<<endl;
    mirrorTree(root);
    return 0;
}