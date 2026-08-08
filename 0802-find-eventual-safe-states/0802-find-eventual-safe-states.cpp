class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& nodes,vector<int>& path,vector<int>& vis){
        vis[node] = 1;
        path[node] = 1;
        for(auto x: adj[node]){
            if(path[x]) return false;
            if(!vis[x]&&!dfs(x,adj,nodes,path,vis)) return false;
        }
        path[node] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j =0; j<graph[i].size();j++){
                v.push_back(graph[i][j]);
            }
            adj[i]= v;
        }
        vector<int> visited(n,0);
        vector<int> path(n,0);
        vector<int> nodes;
        vector<int> ans;
        for(int i=0; i<adj.size(); i++){
            if(dfs(i,adj,nodes,path,visited)) ans.push_back(i);
        }
        for(auto x: ans) nodes.push_back(x);
        return ans;
    }
};