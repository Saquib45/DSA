#include<iostream>
using namespace std;
#include<queue>
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
TreeNode* input(TreeNode* root){
    cout<<"Enter the root data:"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    if(root==NULL) return NULL;
    queue<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp=st.front();
        st.pop();
        cout<<"enter the left data of:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            TreeNode* leftnode=new TreeNode(leftdata);
            temp->left=leftnode;
            st.push(leftnode);
        }

        cout<<"enter the right data of:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            TreeNode* rightnode=new TreeNode(rightdata);
            temp->right=rightnode;
            st.push(rightnode);
        }
    }
}
int main(){
    TreeNode* root=NULL;
    root=input(root);
    return 0;
}