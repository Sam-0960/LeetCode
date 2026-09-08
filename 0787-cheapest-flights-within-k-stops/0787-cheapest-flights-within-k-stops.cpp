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
        while(!pq.empty()){
            auto [stops,dis, node] = pq.top();
            pq.pop();
            if(stops >= k+1) continue;
            for(auto [child,w] : adj[node]){
                if(dist[child] >  dis+ w && stops <= k){
                    dist[child] =  dis + w;
                    pq.push({ stops+1,dist[child], child});
                }
            }
        }
        return (dist[dst] == INT_MAX)? -1: dist[dst];
    }
};