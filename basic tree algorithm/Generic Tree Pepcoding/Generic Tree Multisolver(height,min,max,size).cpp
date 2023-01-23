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

int max_node=INT16_MIN;
int min_node=INT16_MAX;
int size_tree=0;
int height=0;


void multisolver(Node *root,int depth){

    //pre
    height=max(height,depth);
    max_node=max(max_node,root->data);
    min_node=min(min_node,root->data);
    size_tree++;
    for(auto child:root->children){
        multisolver(child,depth+1);
    }
    // post
}


int main()
{
//     12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    multisolver(root,0);
    cout<<"max node==>"<<max_node<<endl;
    cout<<"min node==>"<<min_node<<endl;
    cout<<"size ==>"<<size_tree<<endl;
    cout<<"height==>"<<height<<endl;
  
    return 0;
}