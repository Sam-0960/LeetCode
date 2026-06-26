class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end(),greater<int>());
        int n = asteroids.size();
        int index = -1;
        int i = 0;
        for(i = 0; i<n ; i++){
            if(mass >= asteroids[i]){
                index = i ;  break;
            }
        }
        if(index == -1) return false;
        long long sum = mass;
        for(int i = index; i<n ; i++){
            sum += asteroids[i];
        }
        for(int i = index-1; i>= 0; i--){
            if(asteroids[i] > sum) return false;
            sum += asteroids[i];
        }
        return true;
    }
};