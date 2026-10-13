class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& bridges, vector<int>& t_in, vector<int>& low,vector<int>& vis){
        vis[node] = 1;
        t_in[node] = timer;
        low[node] = timer;
        timer++;
        for(auto child: adj[node]){
            if(child == parent) continue;
            if(!vis[child]){
                dfs(child, node, adj, bridges, t_in,low,vis);
                low[node] = min(low[node],low[child]);
                if(low[child] > t_in[node]){
                    vector<int> v;
                    v.push_back(node);
                    v.push_back(child);
                    bridges.push_back(v);
                }
            }else if(vis[child]){
                low[node] =  min(low[node],low[child]);
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<vector<int>> bridges;
        vector<int> t_in (n,-1);
        vector<int> low (n,-1);
        vector<int> vis (n,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, bridges, t_in, low, vis);
            }
        }
        return bridges;
    }   
};