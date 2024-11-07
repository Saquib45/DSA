#include<iostream>
using namespace std;
#include<queue>
#include<unordered_map>

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
void vertical_traversal(TreeNode* &root){
    unordered_map<int,unordered_map<int,vector<int>>> map; 
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        TreeNode* frontnode=temp.first;
        int hd=temp.second.first;
        int level=temp.second.second;
        map[hd][level].push_back(frontnode->data);
        if(frontnode->left){
            q.push({frontnode->left,{hd-1,level+1}});
        }
        if(frontnode->right){
            q.push({frontnode->right,{hd+1,level+1}});
        }
    }
    for(auto i:map){
        for(auto j:i.second){
            for(auto k:j.second){
                cout<<k<<" ";
            }

        }
    }
}
int main(){
    TreeNode* root=NULL;
    root=input(root);
    cout<<"vertical traversal"<<endl;
    vertical_traversal(root);
}