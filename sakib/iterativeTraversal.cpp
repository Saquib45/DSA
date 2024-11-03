#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

TreeNode* input(TreeNode* &root){            //take preordered-wise input
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    if(data==-1) return NULL;
    root=new TreeNode(data);
    cout<<"enter the left data of:"<<data<<endl;
    input(root->left);
    cout<<"enter the right data of:"<<data<<endl;
    input(root->right);
    return root;
}


void iterative_preordered(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
}

void iterative_postordered(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }

        else {
            TreeNode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }

            else{
                curr=temp;
            }

        }
    }
}

void iterative_inordered(TreeNode* root){
    TreeNode* temp=root;
    stack<TreeNode*> st;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}

int main(){
    TreeNode* root=NULL;
    root=input(root);
    cout<<"output of preordered"<<endl;
    iterative_preordered(root);
    
    cout<<endl<<"output of postordered"<<endl;
    iterative_postordered(root);

    cout<<endl<<"output of inordered"<<endl;
    iterative_inordered(root);

    return 0;
}