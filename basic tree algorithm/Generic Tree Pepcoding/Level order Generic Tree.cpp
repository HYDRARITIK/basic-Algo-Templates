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
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    // q.push(nullptr);

    int z = q.size();
    // bfs
    while (z--)
    {

        cout << q.front()->data << " ";
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            q.push(q.front()->children[i]);
        }
        q.pop();

        if (z == 0)
        {
            cout << endl;
            z = q.size();
        }
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
    levelOrderTraversal(root);
    return 0;
}