class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];int v = edges[i][1];int w = edges[i][2];
            adj[u].push_back({v,w});adj[v].push_back({u,w});
        }
        vector<vector<int>> final;
        for(int i = 0; i<n; i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            vector<int> dist(n,INT_MAX);
            int src = i;
            dist[src] = 0;
            q.push({0,src});
            while(!q.empty()){
                auto [dis,node] = q.top();q.pop();
                for(auto [child,w]: adj[node]){
                    if(dist[child] > dist[node]+w && dist[node]+w <= distanceThreshold){
                        dist[child] = dist[node] +w;
                        q.push({dist[child],child});
                    }
                }
            }
            final.push_back(dist);
        }
        int ans = -1;
        int mincity = INT_MAX;
        for(auto i=0;i<n ;i++){
            int cities = 0;
            for(auto j=0;j<n;j++){
                if(final[i][j]!= INT_MAX && final[i][j] <= distanceThreshold) cities++;
            }
            if(cities <= mincity){
                ans = i;
                mincity = cities;
            }
        }
        return ans;
    }
};