class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        const int MOD = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long> pathCount(n,0);
        vector<long long> distance(n,LLONG_MAX);
        pq.push({0,0});
        distance[0] = 0; pathCount[0] = 1;
        while(!pq.empty()){
            auto [dis,node] = pq.top();pq.pop();
            if(dis != distance[node]) continue;
            for(auto [child,w]: adj[node]){
                if(distance[child] == distance[node]+w) pathCount[child]= (pathCount[child] +pathCount[node])%MOD;
                else if(distance[child] > distance[node]+w){
                    distance[child] = distance[node]+w;
                    pathCount[child] = pathCount[node];
                    pq.push({distance[child],child});
                }
            }
        }
        
        int ans = pathCount[n-1] % MOD;
        return ans;
    }
};