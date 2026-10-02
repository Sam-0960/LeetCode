class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> probabilities(n,0);
        priority_queue<pair<double,double>> pq;
        probabilities[start_node] = 1;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [p, node] = pq.top(); pq.pop();
            if(p < probabilities[node]) continue;
            for(auto [child,prob]: adj[node]){
                if(probabilities[child] < probabilities[node] * prob){
                    probabilities[child] = probabilities[node] * prob;
                    pq.push({probabilities[child],child});
                }
            }
        }
        return probabilities[end_node];
    }
};