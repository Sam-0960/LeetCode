class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<vector<int>>& graph,vector<int>& vis,vector<int>& color){
        vis[i] = 1;
        bool val = true;
        for(auto x: adj[i]){
            if(color[i] == 1){
                if(!vis[x]){
                    color[x] = 0;
                    val = dfs(x,adj,graph,vis,color);
                    if(val == false) return false;
                }else{
                    if(color[x] == 1) return false;
                }
            }else{
                if(!vis[x]){
                    color[x] = 1;
                    val = dfs(x,adj,graph,vis,color);
                    if(val == false) return false;
                }else{
                    if(color[x] == 0) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>> adj;vector<int> vis1(graph.size(),0);vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            vector<int> ans;
            for(int j =0; j<graph[i].size();j++){
                ans.push_back(graph[i][j]);
            }
            adj.push_back(ans);
        }
        // 1-> A 0-> B
        color[0] = 1;bool val = true;
        for(int i = 0; i<adj.size();i++){
            if(!vis1[i]){
                if(!dfs(i,adj,graph,vis1,color)) return false;
            }
        }
        return true;
    }
};