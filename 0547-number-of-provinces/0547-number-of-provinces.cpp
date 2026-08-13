class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj,vector<int>&  visited){
        queue<int> q;
        q.push({node});
        visited[node] = 1;
        while(!q.empty()){
            int x = q.front();q.pop();
            for(auto child : adj[x]){
                if(!visited[child] && adj[node][child]){
                    visited[child]=1;
                    q.push(child);
                }
            }
        }
        return 1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int prov = 0;
        vector<int> vis(n,0);
        for(int node = 0; node< n;node++){
            if(!vis[node]) prov += bfs(node,isConnected,vis);
        }
        return prov;
    }
};