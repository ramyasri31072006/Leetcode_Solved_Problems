class DSU{
    public:
    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v =  findUpar(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] >rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU ds(n*m);

        

        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == '1'){

                    
                    int node = i*m + j;

                    for(int k = 0; k < 4; k++){

                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        int neiNode = nr*m+nc;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < m &&  grid[nr][nc] == '1' ){
                           
                            if(ds.findUpar(node) != ds.findUpar(neiNode)){
                                ds.UnionByRank(node,neiNode);
                            }
                        }
                    }

                }
            }
        }
        int island = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                int node = i*m+j;
                if(grid[i][j] == '1' && ds.findUpar(node) == node){
                    island++;
                }
            }
        }
        return island;

    }
};