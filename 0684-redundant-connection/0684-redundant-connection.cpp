class Solution {
public:
    int findPar(int node,vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    bool unite(int u, int v, vector<int>& parent, vector<int>& rank){
        int a = findPar(u,parent); int b = findPar(v,parent);
        if(a == b) return false;
        if(rank[a] < rank[b]){
            parent[a] = b;
        }else if(rank[b] < rank[a]){
            parent[b] = a;
        }else{
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        iota(parent.begin(),parent.end(),0); 
        vector<int> rank(n+1,0);
        for(int i =0;i<edges.size();i++){
            if(!unite(edges[i][0],edges[i][1],parent,rank)) return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};