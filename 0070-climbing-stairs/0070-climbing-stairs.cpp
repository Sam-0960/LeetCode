class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        pair<int,int> p;
        p.first = 1;
        p.second = 2;
        for(int i =3 ; i<= n ; i++){
            int el = p.first + p.second;
            p.first = p.second;
            p.second = el;
        }
        return p.second;
    }
};