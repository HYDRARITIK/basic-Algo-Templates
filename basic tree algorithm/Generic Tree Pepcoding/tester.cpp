#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *construct(int *arr, int n)
{
    Node *root = new Node();
    root->data = arr[0];
    stack<Node *> st;
   

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node();
            t->data = arr[i];

            if (st.size() > 0)
            {
                Node *top_elem = st.top();
                top_elem->children.push_back(t);
            }
            else
            {
                root = t;
            }

            st.push(t);
        }

        return root;
    }
}
    // void display(Node * root)
    // {
    //     cout << root->data << "->";
    //     for (int i = 0; i < root->children.size(); i++)
    //     {
    //         cout << root->children[i]->data << ", ";
    //     }
    //     cout << "." << endl;
    //     for (int i = 0; i < root->children.size(); i++)
    //     {
    //         display(root->children[i]);
    //     }

    // }


void display(Node *root) {
   cout << root->data << "->";
    for (int i = 0; i < root->children.size(); i++) {
      cout << root->children[i]->data << ", ";
    }
    cout << "." << endl;

    for (auto child : root->children) {
      display(child);
    }
  }









    int height(Node * root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        int a = -1;
        for (int i = 0; i < root->children.size(); i++)
        {
            a = max(a, height(root->children[i]));
        }

        return a + 1;
    }
    int main()
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Node *root = construct(arr, n);
        display(root);
        // cout << height(root) << endl;
        return 0;
    }