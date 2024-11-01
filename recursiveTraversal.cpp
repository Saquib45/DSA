#include<iostream>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    public:
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

TreeNode* input(TreeNode* &root){
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    if(data==-1) return NULL;
    root=new TreeNode(data);
    cout<<"enter the data for left of:"<<data<<endl;
    input(root->left);
    cout<<"enter the data for right of:"<<data<<endl;
    input(root->right);
    return root;
}

void Recursive_preordered(TreeNode* root){  
    if(root==NULL) return;
    cout<<root->data<<" ";
    Recursive_preordered(root->left);
    Recursive_preordered(root->right);
}

int main(){
    TreeNode* root=NULL;
    root=input(root);
    Recursive_preordered(root);
    return 0;
}