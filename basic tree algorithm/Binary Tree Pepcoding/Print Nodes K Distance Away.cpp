#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


Node* construct(int *arr){
   Node* root=new Node(arr[0]);
   pair<Node*,int> p={root,1};
   
   stack<pair<Node*,int>> st;
   st.push(p);
    
    int idx=1;
    while(!st.empty()){
        // pair<Node*,int> pe=st.top();
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
              st.top().first->right = new Node(arr[idx]);
              pair<Node*,int> rp={st.top().first->right,1};
                st.push(rp);
            } else {
              st.top().first->right = nullptr;
            }
            idx++;
        } 
        else {
            st.pop();
        }
        
    }
    return root;
}


vector<Node*> nodetorootpath(Node* root,int data){
	if(root==nullptr){
		vector<Node*> n;
		return n;
	}

	if(root->data==data){
		vector<Node*> n;
		n.push_back(root);
		return n;
	}

    //calling left child
	vector<Node*> ans=nodetorootpath(root->left,data);

	if(ans.size()>0){
		ans.push_back(root);
		return ans;
	}
    //calling right child
	ans=nodetorootpath(root->right,data);
	if(ans.size()>0){
		ans.push_back(root);
		return ans;
	}
	return ans;
}

void printKLevelsDown(Node* root,int k,Node* hurdle){
    if(root==nullptr || root==hurdle){
        return;
    }
    
    if(k==0){
        cout << root->data << endl;
        return;
    }
    
    printKLevelsDown(root->left,k-1,hurdle);
    printKLevelsDown(root->right,k-1,hurdle);
}

void KFar(Node* root,int x,int k){
    vector<Node*> ntrp=nodetorootpath(root,x);
    Node* hurdle=nullptr;
    
    for(int i=0;i<ntrp.size();i++){
        Node* temp=ntrp[i];
        printKLevelsDown(temp,k-i,hurdle);
        hurdle=temp;
    }
}



int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x=="n"){
            v[i]=-1;
            
        }
        else{
            v[i]=stoi(x);
        }
    }
    int x,k;
    cin >>x>> k;
    Node* root=construct(v);
    // display(root);
    KFar(root,x,k);
    
    
}