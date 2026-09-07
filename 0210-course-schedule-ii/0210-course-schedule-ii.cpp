class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indeg(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
    
        queue<int> q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i] == 0){
                q.push(i);
                ans.push_back(i);
            } 
        } 

        while(!q.empty()){
            auto node = q.front(); q.pop();
            for(auto child : graph[node]){
                indeg[child]--;
                if(indeg[child] == 0){
                    ans.push_back(child);
                    q.push(child);
                } 
               
            }
        }
        int a = accumulate(indeg.begin(),indeg.end(),0LL);
        if(a>0) return {};
        return ans;
    }
};