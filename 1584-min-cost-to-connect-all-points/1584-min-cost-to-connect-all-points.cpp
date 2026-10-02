class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> nodes;
        for(int i=0;i<n;i++){
            nodes.push_back({points[i][0],points[i][1]});
        }

        vector<tuple<int,int,int>> edges;
        for(int u=0; u<n ; u++){
            for(int v = u+1; v<n ; v++){
                int dist = abs(nodes[v].first - nodes[u].first) + abs(nodes[v].second - nodes[u].second);
                edges.push_back({dist,u,v});
            }
        }

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            auto [w,u,v] = edges[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> vis(n,0);
        priority_queue<tuple<int,int,int> ,  vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,0,-1});
        int ans = 0;
        while(!pq.empty()){
            auto [w,node,parent] = pq.top(); pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            ans += w;
            for(auto [child,wt] : adj[node]){
                if(!vis[child]){
                    pq.push({wt,child,node});
                }
            }
        }

        return ans;
    }
};