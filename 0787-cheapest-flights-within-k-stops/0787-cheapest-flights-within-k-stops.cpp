class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> cost(n,vector<int>(k+2,INT_MAX));
        cost[src][0] =  0;
        pq.push({0,src,cost[src][0]});
        while(!pq.empty()){
            auto [dist, node ,stops] = pq.top();
            pq.pop();
            if(stops > k+1) continue;
            for(auto [child,w] : adj[node]){
                if(stops+1 <= k+1 && cost[child][stops+1] > dist + w){
                    cost[child][stops+1] = dist + w;
                    pq.push({cost[child][stops+1],child,stops+1});
                }
            }
        }
        int mini = INT_MAX;
        for(auto i= 0; i<k+2; i++){
            mini = min(mini,cost[dst][i]); 
        }
        return (mini == INT_MAX)? -1: mini;
    }
};