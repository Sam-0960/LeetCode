class Solution {
public:
    bool dfs(int u,vector<vector<int>>& prerequisites,vector<vector<int>>& adj,vector<int>& vis,vector<int>&path){
        vis[u] = 1;
        path[u] = 1;
        for(auto x:adj[u]){
            if(!vis[x]){
                if(!dfs(x,prerequisites,adj,vis,path)) return false;
            } 
            if(path[x]) return false;
            
        }
        path[u] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses,0);
        for(int i = 0; i<numCourses;i++){
            if(!visited[i]){
                vector<int>path(numCourses,0);
                if(!dfs(i,prerequisites,adj,visited,path)) return false; 
            }
        }
        return true;
    }
};