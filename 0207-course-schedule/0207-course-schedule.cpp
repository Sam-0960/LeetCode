class Solution {
public:
    bool cycle(int node, vector<vector<int>>& graph, vector<int>& vis,vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        for(auto child: graph[node]){
            if(path[child]) return false;
            if(vis[child]) continue;
            if(!cycle(child,graph,vis,path)) return false;
        }
        path[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(int i=0; i<prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);        
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0; i<n ; i++){
            if(!vis[i]){
                if(!cycle(i,adj,vis,path)) return false;;
            }
        }
        return true;
    }
};