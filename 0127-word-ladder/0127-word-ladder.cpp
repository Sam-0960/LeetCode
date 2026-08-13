class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(),wordList.end());
        if(list.find(endWord) == list.end()) return 0;
        unordered_set<string>st;
        int ans = 0;
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        st.insert(beginWord);
        while(!q.empty()){
            auto [cnt,curr] = q.front();q.pop();
            if(curr == endWord) return cnt;
            for(int i = 0; i<curr.size(); i++){
                for(int j = 0; j<26; j++){
                    string next = curr;
                    next[i] = 'a' +j;
                    if(st.find(next) == st.end() && list.find(next) != list.end()){
                        q.push({cnt+1,next});
                        st.insert(next);
                    }
                }
            }
        }
        return ans;
    }
};