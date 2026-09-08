class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i = 0; i<times.size() ; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [w,node] = pq.top();
            pq.pop();
            if(dis[node] < w) continue;
            for(auto [child,weight]: graph[node]){
                if(dis[child] > dis[node] + weight){
                    dis[child] = dis[node] + weight;
                    pq.push({dis[child],child});
                }
            }
        }
        int res = *max_element(dis.begin()+1,dis.end());
        return (res == INT_MAX)? -1 : res;
    }
};