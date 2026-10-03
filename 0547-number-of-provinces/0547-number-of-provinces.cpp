class Solution {
public:
    int findPar(int node, vector<int>& parent){ 
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    bool unite(int x, int y ,vector<int>& parent, vector<int>& rank){
        int a = findPar(x,parent) ; int b = findPar(y,parent);
        if(a == b) return false;
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[b] < rank[a]) parent[b] = a;
        else{
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        vector<int> rank(n,0);
        int comps = n;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j]){
                    if(unite(i,j,parent,rank))
                        comps--;
                }
            }
        }
        
        return comps;
    }
};