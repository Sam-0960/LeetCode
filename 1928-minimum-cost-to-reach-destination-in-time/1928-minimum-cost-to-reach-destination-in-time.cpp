class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<vector<int>> money(n,vector<int>(maxTime+1,INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({passingFees[0],0,maxTime});
        money[0][maxTime] = passingFees[0];
        while(!pq.empty()){
            auto [currfee, node, currtime] = pq.top(); pq.pop();
            if(currtime <= 0) continue;
            for(auto [child,t] : adj[node]){
                if(currtime - t >= 0 && money[child][currtime-t] > money[node][currtime] + passingFees[child]){
                    money[child][currtime-t] = money[node][currtime] + passingFees[child];
                    pq.push({money[child][currtime-t], child, currtime - t});
                }
            }
        }
        int ans = INT_MAX;
        for(auto x:money[n-1]){
            ans = min(ans,x);
        }
        return (ans == INT_MAX)?-1:ans;
    }
};