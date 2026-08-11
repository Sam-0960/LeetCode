class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> distance(n,INT_MAX);
        queue<tuple<int,int,int>> q;
        distance[src] = 0;
        q.push({0,src,0});
        while(!q.empty()){
            auto [stops,node,dist] = q.front();q.pop();
            if(stops>k) continue;
            for(auto [child,weight]: adj[node]){
                if(distance[child] > dist+weight && stops <= k){
                    distance[child] = dist+weight;
                    q.push({stops+1,child,distance[child]});
                }
            }
        }
        return (distance[dst] == INT_MAX)? -1: distance[dst];
    }
};