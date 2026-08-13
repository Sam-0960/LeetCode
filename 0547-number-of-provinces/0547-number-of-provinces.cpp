class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj,vector<int>&  visited){
        queue<int> q;
        q.push({node});
        visited[node] = 1;
        while(!q.empty()){
            int x = q.front();q.pop();
            for(int i =0;i<adj[x].size();i++){
                if(!visited[i] && adj[x][i] == 1){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int prov = 0;
        vector<int> vis(n,0);
        for(int node = 0; node< n;node++){
            if(!vis[node]){ 
                bfs(node,isConnected,vis);
                prov++;
            }
        }
        return prov;
    }
};