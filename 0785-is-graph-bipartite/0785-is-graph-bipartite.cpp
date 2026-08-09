class Solution {
public:
    bool bfs(int node, vector<vector<int>>& adj, vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int n = q.size();
            int x = q.front();q.pop();
            for(auto child: adj[x]){
                if(color[child] ==  color[x]) return false;
                else if(color[child] == -1){
                    color[child] = !color[x];
                    q.push(child);
                }else continue;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0; i<graph.size();i++){
            if(color[i]==-1 && !bfs(i,graph,color)) return false;
        }
        return true;
    }
};