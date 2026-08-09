class Solution {
public:
    bool dfs(int i, vector<vector<int>>&adj,vector<int>& path,vector<int>& vis,vector<int>& ans){
        vis[i] = 1;
        path[i] = 1;
        for(auto x: adj[i]){
            if(path[x] == 1) return false;
            if(!vis[x] && !dfs(x,adj,path,vis,ans)) return false;
        }
        path[i] = 0;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n ;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        vector<int> path(numCourses,0);
        vector<int> vis(numCourses,0);
        for(int i =0 ; i<numCourses; i++){
            if(!vis[i] && !dfs(i,adj,path,vis,ans)) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};