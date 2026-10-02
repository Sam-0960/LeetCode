class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long mod = 1e9+7;
        vector<vector<pair<long long,long long>>> adj(n);
        for(int i=0; i<roads.size() ;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        vector<long long> ways(n,0);
        ways[0] = 1;
        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if(d > dist[node]) continue; // to prevent itn of stale entries
            for(auto [child,w]: adj[node]){
                if(dist[child] > dist[node] + w){
                    dist[child] = dist[node] + w;
                    ways[child] = ways[node];
                    pq.push({dist[child],child});
                }else if(dist[child] == dist[node]+w){
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }
        return (int) (ways[n-1]%mod);
    }
};