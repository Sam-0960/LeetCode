class Solution {
public:
    int func(unordered_set<string>& st, string beginWord,string endWord){
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [w,k] = q.front();q.pop();
            if(w == endWord) return k;
            for(int i=0; i<beginWord.size();i++){
                for(char ch = 'a'; ch<='z'; ch++){
                    string s = w;
                    s[i] = ch;
                    if(st.find(s)!= st.end() && s!= w){
                        st.erase(s);
                        q.push({s,k+1});
                    }
                }
            }
        }
        return 0;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()) return 0;
        unordered_set<string>st;
        for(auto x: wordList) st.insert(x);       
        return func(st,beginWord,endWord);
    }
};