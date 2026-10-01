class Solution {
public:
    vector<char> letters = {'A','C','G','T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),endGene) == bank.end()) return -1;
        unordered_set<string>st;
        for(auto x: bank) st.insert(x);
        queue<pair<string,int>> q;
        q.push({startGene,0});
        int n = startGene.size();
        while(!q.empty()){
            auto [s,d] = q.front(); q.pop();
            if(s == endGene) return d;
            for(int i=0; i<n;i++){
                string word = s;
                for(auto ch: letters){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,d+1});
                    }
                }
            }
        }
        return -1;
    }
};