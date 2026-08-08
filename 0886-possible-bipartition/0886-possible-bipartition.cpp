class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj, vector<vector<int>>& dislikes,vector<int>& color){
        if(color[i] == -1) color[i] = 1;
        for(auto x: adj[i]){
            if(color[x] == -1){
                color[x] = !color[i];
                if(!dfs(x,adj,dislikes,color)) return false;
            }else{
                if(color[x] == color[i]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < dislikes.size(); i++) {

            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        //1->like 0->dislike
        for(int i=1;i<=n;i++){
            if(color[i] == -1 && !dfs(i,adj,dislikes,color)) return false;
        }
        
        return true;
    }
};