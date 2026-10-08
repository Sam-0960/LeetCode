class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node], parent);
    }
    void unite(int x, int y , vector<int>& parent, vector<int>& size){
        int a = findPar(x, parent);int b = findPar(y, parent);
        if(a == b) return;
        if(size[a] >= size[b]){
            size[a] += size[b];
            parent[b] = a;
        }
        else{
            size[b] += size[a];
            parent[a] = b;
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0);
        vector<int> size(n,1);
        set<int> st;
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n ;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unite(i,j,parent,size);
                }
            }
        }
        for(auto i=0; i<n; i++) st.insert(findPar(i,parent));
        int ans = 0;
        for(auto x: st) ans += (size[x]-1);
        return ans;
    }
};