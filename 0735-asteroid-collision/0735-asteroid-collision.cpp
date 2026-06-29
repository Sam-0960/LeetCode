class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();stack<int> st;
        for(int i=0; i<n ;i++){
            int el = asteroids[i];
            if(el > 0) st.push(el);
            else{
                while(!st.empty() && st.top()>0 && st.top() < abs(el)) st.pop();
                if(!st.empty() && st.top() == abs(el)){
                    st.pop(); continue;
                }else if(!st.empty() && st.top()> abs(el)) continue;
                st.push(el);
            }    
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};