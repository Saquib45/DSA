#include<iostream>
using namespace std;
#include<queue>
#include<unordered_map>
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
    queue<TreeNode*> q;
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
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


void leftview(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            ans[i]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<ans[0]<<" ";
    }
}

void rightview(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            ans[size-1-i]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<ans[0]<<" ";
    }
}

void topview(TreeNode* root){
    unordered_map<int,int> map;
    if(root==NULL) return;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        TreeNode* frontnode=temp.first;
        int hd=temp.second;
        if(map.find(hd)==map.end()){
            map[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push({frontnode->left,hd-1});
        }
        if(frontnode->right){
            q.push({frontnode->right,hd+1});
        }
    }
    for(auto i:map){
        cout<<i.second<<" ";
    }
}

void bottomview(TreeNode* root){
    unordered_map<int,int> map;
    if(root==NULL) return;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        TreeNode* frontnode=temp.first;
        int hd=temp.second;
        map[hd]=frontnode->data;
        if(frontnode->left){
            q.push({frontnode->left,hd-1});
        }
        if(frontnode->right){
            q.push({frontnode->right,hd+1});
        }
    }
    for(auto i:map){
        cout<<i.second<<" ";
    }
}
int main(){
    TreeNode* root=NULL;
    root=input(root);
    cout<<"left veiw:";
    leftview(root);
    cout<<endl<<"right view:";
    rightview(root);
    cout<<endl<<"topview:";
    topview(root);
    cout<<endl<<"bottom view:";
    bottomview(root);
}