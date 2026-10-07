class Solution {
public:
    bool isValid(int x, int y, int n){
        if(x < 0 || x >= n || y < 0 || y >= n) return false;
        return true;
    }
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int findPar(int node , vector<int>& par){
        if(node == par[node]) return node;
        return par[node] = findPar(par[node],par);
    }
    void unite(int x, int y, vector<int>& parent, vector<int>& size){
        int a = findPar(x,parent); int b = findPar(y,parent);
        if(a == b) return;
        if(size[a] > size[b]){
            size[a] += size[b];
            parent[b] = a; 
        }else if(size[b] > size[a]){
            size[b] += size[a];
            parent[a] = b;
        }else{
            size[a] += size[b];
            parent[b] = a;
        }
        return;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int>parent(n*n);
        iota(parent.begin(),parent.end(),0);
        vector<int> size(n*n,1);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 0) continue;
                int node = i*n + j;
                for(auto [dx,dy] :dir){
                    int adjNode = (i+dx)*n + (j+dy);
                    if(isValid(i+dx,j+dy,n) && grid[i+dx][j+dy] == 1){
                        unite(node,adjNode,parent,size);
                    }
                }
            }
        }

        int max_size = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 1) continue;
                int node = i*n + j;
                set<int> comps;
                for(auto [dx,dy] :dir){
                    int adjNode = (i+dx)*n + (j+dy);
                    if(isValid(i+dx,j+dy,n) && grid[i+dx][j+dy] == 1){
                        comps.insert(findPar(adjNode,parent));
                    }
                }
                int currsize = 0;
                for(auto x:comps) currsize += size[x];
                max_size = max(max_size,currsize+1);
            }
        }

        return (max_size == 0)? n*n : max_size;
    }
};