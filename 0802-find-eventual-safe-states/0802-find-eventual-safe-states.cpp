class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& path,vector<int>& vis){
        vis[i] = 1;path[i] = 1;
        for(auto x: graph[i]){
            if(path[x]) return false;
            if(!vis[x] && !dfs(x,graph,path,vis)) return false;
        }
        path[i] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> path(graph.size(),0);
        vector<int> vis(graph.size(),0);
        for(int i=0 ; i<graph.size(); i++){
            if(dfs(i, graph,path,vis)) ans.push_back(i);
        }
        
        return ans;
    }
};