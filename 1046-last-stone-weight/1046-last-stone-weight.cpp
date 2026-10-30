class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size() > 1){
            int biggest = pq.top();pq.pop();
            int sec_big = pq.top();pq.pop();
            if(biggest > sec_big){
                pq.push(biggest-sec_big);
            }
        }
        return (pq.size() == 0)? 0: pq.top();
    }
};