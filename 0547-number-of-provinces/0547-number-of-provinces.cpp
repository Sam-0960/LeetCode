class Solution {
public:
    void bfs(int node,vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int x = q.front();q.pop();
            for(auto child : adj[x]){
                if(!vis[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n ;i++){
            for(int j = 0 ; j <isConnected[i].size();j++){
                if(isConnected[i][j] == 1 && i!= j){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};