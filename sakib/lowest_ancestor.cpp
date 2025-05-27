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

TreeNode* input(TreeNode* &root){
    cout<<"Enter the root data:"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    if(root==NULL) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front ();
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

TreeNode* ancestor(TreeNode* root,int first,int second){
    if(root==NULL || root->data==first || root->data==second) return root;
    TreeNode* left=ancestor(root->left,first,second);
    TreeNode* right=ancestor(root->right,first,second);
    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
}

int main(){
 TreeNode* root=input(root);
 cout<<"enter the first node data:";
 int firstdata;
 cin>>firstdata;
 TreeNode* first=new TreeNode(firstdata);
 cout<<"enter the second node data:";
 int seconddata;
 cin>>seconddata;
 TreeNode* second=new TreeNode(seconddata);
 cout<<"lowest common ancestor is:"<<ancestor(root,firstdata,seconddata)->data;
}