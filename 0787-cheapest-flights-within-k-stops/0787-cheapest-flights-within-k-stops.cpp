class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i =0 ; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        int ans = INT_MAX;
        while(!pq.empty()){
            auto [stops,node, d] = pq.top();
            pq.pop();
            if(node == dst && stops <= k+1) ans= min(ans,d);
            if(stops >= k+1) continue;
            for(auto [child,w] : adj[node]){
                if(dist[child] >  d+ w && stops <= k){
                    dist[child] =  d + w;
                    pq.push({ stops+1,child,dist[child]});
                }
            }
        }
        return (ans == INT_MAX)? -1: ans;
    }
};