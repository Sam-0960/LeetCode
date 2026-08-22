class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> year(1002,0);
        for(auto x:logs){
            year[x[0]-1950+1]++;
            year[x[1]-1950+1]--;
        }
        for(int i=1;i<year.size();i++)
            year[i] = year[i]+year[i-1];
        pair<int,int> ans = {INT_MIN,0};
        for(int i = 0; i<year.size();i++){
            if(year[i] > ans.first){
                ans.first = year[i];
                ans.second = i+1949; 
            }
        }
        return ans.second;
    }
};