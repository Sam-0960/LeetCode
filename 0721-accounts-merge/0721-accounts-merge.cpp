class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    void unite(int x, int y, vector<int>& parent, vector<int>& rank){
        int a = findPar(x,parent); int b = findPar(y,parent);
        if(a == b) return ;
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[b] < rank[a]) parent[b] = a;
        else{
            parent[b] = a;
            rank[a]++;
        }
        return ;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(),0);
        vector<int> rank(n,0);

        unordered_map<int, string> names;
        for(int i=0; i< n;i++){
            names[i] = accounts[i][0];
        }

        unordered_map<string,int> mails;
        for(int i =0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                if(mails.find(accounts[i][j]) != mails.end()){
                    unite(mails[accounts[i][j]],i,parent,rank);
                }else
                    mails[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> ans(n);
        for(auto x:names){
            int node = findPar(x.first,parent);
            if(node == x.first)
                ans[node].push_back(names[node]);
        }
        for(auto x:mails){
            int p = findPar(x.second,parent);
            ans[p].push_back(x.first);
        }
        for(int i = 0; i < n; i++){
            if(!ans[i].empty()){
                sort(ans[i].begin() + 1, ans[i].end());
            }
        }

        vector<vector<string>> result;

        for(int i = 0; i < n; i++){
            if(!ans[i].empty()){
                result.push_back(ans[i]);
            }
        }

        return result;
    }
};