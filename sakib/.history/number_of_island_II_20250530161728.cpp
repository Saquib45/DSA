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
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> matrix(n,vector<int>(m,0));
        
        vector<pair<int,int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
        
        DisjointSet ds(n*m);
        
        int cnt=0;
        vector<int> ans;
        
        int k=operators.size();
        for(int i=0;i<k;i++){
            
            int x=operators[i][0];
            int y=operators[i][1];
            if(matrix[x][y]==1){
                ans.push_back(cnt);
                continue;
            }
            
            cnt++;
            matrix[x][y]=1;
            for(auto it:direction){
                int newrow=x+it.first;
                int newcol=y+it.second;
                
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && matrix[newrow][newcol]==1){
                    
                    int nodeno=x*m+y;
                    
                    int adjnodeno=newrow*m+newcol;
                    
                    if(ds.Ultimate_parent(nodeno)!=ds.Ultimate_parent(adjnodeno)){
                      cnt--;
                      ds.UnionByRank(nodeno,adjnodeno);
                    }
                }
            }
            
            ans.push_back(cnt);
            
        }
        
        return ans;
        
    }
};