class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size(); i++) if(indegree[i] == 0) q.push(i);
        vector<int>ans;
        while(!q.empty()){
            auto node = q.front();q.pop();
            ans.push_back(node);
            for(auto child: adj[node]){
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }
        }
        int sum = accumulate(indegree.begin(),indegree.end(),0LL);
        if(sum>0) return {};
        return ans;
    }
};