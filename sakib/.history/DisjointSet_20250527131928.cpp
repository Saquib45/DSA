#include<iostream>
using namespace std;
#include<vector>
class DisjointSet {
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int Ultimate_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=Ultimate_parent(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ultimate_parent_u=Ultimate_parent(u);
        int ultimate_parent_v=Ultimate_parent(v);
        if(ultimate_parent_u==ultimate_parent_v){
            return;
        }
        if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }

    void UnionBySize(int u,int v){
        int ultimate_parent_u=Ultimate_parent(u);
        int ultimate_parent_v=Ultimate_parent(v);

        if(ultimate_parent_u==ultimate_parent_v){
            return ;
        }

        if(size[ultimate_parent_u]<size[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }

};
int main(){
    DisjointSet s
}