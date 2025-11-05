#include<iostream>
using namespace std;
#include"Treeclass.cpp"
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
    cout<<"enter root data:"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
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

void print_zigzag(TreeNode* root){
    queue<TreeNode*> q;
    if(root==NULL) return ;
    q.push(root);
    bool leftToright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            int index=leftToright?i:size-1-i;
            ans[index]=temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        leftToright=leftToright?false:true;
        for(int i=0;i<size;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    TreeNode* root=NULL;
    root=input(root);
    print_zigzag(root);
    return 0;
}