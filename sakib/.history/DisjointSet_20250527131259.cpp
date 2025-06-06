#include<iostream>
using namespace std;

class DisjointSet {
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
};
int main(){

}