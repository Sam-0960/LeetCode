class Solution {
public:
    bool isPossible(vector<int>& position, int m, long long mid){
        int ballsCount = 1;
        int prevBall = position[0];
        for(auto x: position){
            if(x-prevBall >= mid){
                ballsCount++;
                prevBall = x;
            }else continue;
        }
        return (ballsCount >= m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        long long low = 1;
        long long high = position[position.size()-1] - position[0];
        long long ans = -1;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPossible(position,m,mid)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};