class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i =0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            for(auto x:adj[node]){
                if(dis[x.first] > x.second+dis[node]){
                    dis[x.first] = x.second+dis[node];
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        int ans = *max_element(dis.begin()+1,dis.end());
        return (ans == INT_MAX)? -1: ans;
    }
};