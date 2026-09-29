class Solution {
public:
    bool bfs(vector<vector<int>>& graph ,int start,int color, vector<int>& visited){
        queue<pair<int,int>> q;
        q.push({start,color});
        while(!q.empty()){
            auto [node,color] = q.front(); q.pop();
            for(auto child: graph[node]){
                if(visited[child] == color) return false;
                if(visited[child] == -1){
                    visited[child] = !color;
                    q.push({child,visited[child]});
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 0) return true;
        vector<int> visited(graph.size(),-1) ;
        for(auto i=0; i<graph.size(); i++){
            if(visited[i] == -1 && !bfs(graph,i,1,visited)){
                return false;
            }
        }
        return true;
    }
};