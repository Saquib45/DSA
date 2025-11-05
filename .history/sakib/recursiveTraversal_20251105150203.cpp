#include<iostream>
using namespace std;
#include"Treeclass.cpp"

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

void Recursive_postordered(TreeNode* root){
    if(root==NULL) return;
    Recursive_postordered(root->left);
    Recursive_postordered(root->right);
    cout<<root->data<<" ";
}

void Recursive_inordered(TreeNode* root){
    if(root==NULL) return;
    Recursive_inordered(root->left);
    cout<<root->data<<" ";
    Recursive_inordered(root->right);
    
}


int main(){
    TreeNode* root=NULL;
    root=input(root);
    cout<<"preordered traversal"<<endl;
    Recursive_preordered(root);
    cout<<endl;
    cout<<"postordered traversal"<<endl;
    Recursive_postordered(root);
    cout<<endl;
    cout<<"inordered output"<<endl;
    Recursive_inordered(root);
    return 0;
}