#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    vector<Node *> children;
};

Node* construct(int* arr,int n){
    Node* root=new Node();
    root->data=arr[0];
    stack<Node*> st;
    st.push(root);

    for(int i=1;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node* nn=new Node();
            nn->data=arr[i];
            st.top()->children.push_back(nn);
            st.push(nn);
        }
    }
    return root;
}



int main()
{
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
  
    return 0;
}