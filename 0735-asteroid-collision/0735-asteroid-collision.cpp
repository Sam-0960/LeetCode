class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int el = asteroids[i];
            if (el < 0) {
                while (!st.empty() && abs(el) > st.top() && st.top()>0)
                    st.pop();
                if (!st.empty() && st.top() == abs(el)) {
                    st.pop();
                    continue;
                }
                if (!st.empty() && st.top() > abs(el))
                    continue;
            }
            st.push(el);
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};