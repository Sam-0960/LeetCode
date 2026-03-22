class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 2) return true;
        sort(arr.begin(),arr.end());
        int k = arr[1] - arr[0];
        for(int i = 1 ; i<arr.size()-1; i++){
            if(arr[i]+k != arr[i+1]) return false;
        }
        return true;
    }
};