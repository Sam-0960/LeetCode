class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>distance(n,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        distance[src] = 0;
        int ans = INT_MAX;
        while(!pq.empty()){
            auto [stops,node,d] = pq.top();pq.pop();
            if(node == dst && stops <= k+1) ans= min(ans,d);
            if(stops >= k+1) continue;
            for(auto [child,w] : adj[node]){
                if(distance[child]>d+w){
                    distance[child] = d+w;
                    pq.push({stops+1,child,distance[child]});
                }
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};