class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color){
        if(color[node] == -1) color[node] = 1;
        for(auto x: adj[node]){
            if(color[x] == color[node]) return false;
            if(color[x] == -1){
                color[x] = !color[node];
                if(!dfs(x,adj,color)) return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0; i<graph.size();i++){
            if(color[i]==-1 && !dfs(i,graph,color)) return false;
        }
        return true;
    }
};