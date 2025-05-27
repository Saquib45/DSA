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
    DisjointSet ds(7);

    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);  
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionByRank(5, 6);

    if(ds.Ultimate_parent(1) == ds.Ultimate_parent(7)) {
        cout << "1 and 7 are in the same set." << endl;
    } else {
        cout << "1 and 7 are in different sets." << endl;
    }
    ds.UnionByRank(3, 7);

        if(ds.Ultimate_parent(1) == ds.Ultimate_parent(7)) {
        cout << "1 and 7 are in the same set." << endl;
    } else {
        cout << "1 and 7 are in different sets." << endl;
    }
    return 0;
}