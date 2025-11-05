#include<iostream>
using namespace std;
#include<queue>
#include"Treeclass.cpp"

TreeNode* input(TreeNode* &root){
    cout<<"Enter the root data:"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    if(root==NULL) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        cout<<"enter the left data of:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new TreeNode(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the right data of:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new TreeNode(rightdata); 
            q.push(temp->right);
        }
    }
    return root;
}

void iterative_levelordered(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
    }
}
int main(){
    TreeNode* root=NULL;
    root=input(root);
    cout<<"iterative output:"<<endl;
    iterative_levelordered(root);
    return 0;
}