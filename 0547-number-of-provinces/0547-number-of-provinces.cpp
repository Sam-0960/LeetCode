class Solution {
public:
    int count = 0;
    void dfs(int start,vector<vector<int>>& isConnected,int m, vector<int>& visited){
        visited[start] = 1;
        for(int j = 0;j<m;j++){
            if(!visited[j] && isConnected[start][j]){
                dfs(j,isConnected,m,visited);
            }
            
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> visited(m,0);
        for(int i = 0; i<n; i++){
            if(visited[i] == 0){
                dfs(i,isConnected,m,visited);
                count++;
            }
        }
        return count;
    }
};