class Solution {
public:
    void func(int i, vector<vector<int>>& bombs, int& cnt) {
        queue<tuple<int, int, int>> q;
        q.push({bombs[i][0], bombs[i][1], bombs[i][2]});
        vector<int> vis(bombs.size(),0);
        vis[i] = 1;
        while (!q.empty()) {
            auto [x, y, r] = q.front();
            q.pop();
            for (int j = 0; j < bombs.size(); j++) {
                if (pow(bombs[j][0] - x, 2) + pow(bombs[j][1] - y, 2) <= pow(r, 2) && !vis[j])
                {
                    vis[j] = 1;
                    q.push({bombs[j][0],bombs[j][1],bombs[j][2]});
                    cnt++;
                }
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        for (int i = 0; i < bombs.size(); i++) {
            int cnt = 1;
            func(i, bombs, cnt);
            res = max(res, cnt);
        }
        return res;
    }
};