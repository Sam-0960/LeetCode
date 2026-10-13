class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    bool unite(int x, int y , vector<int>& parent, vector<int>& size){
        int a = findPar(x,parent) ; int b = findPar(y,parent);
        if(a == b ) return false;
        if(size[a] < size[b]){
            size[b] += size[a];
            parent[a] = b;
            return true;
        }
        size[a] += size[b];
        parent[b] = a;
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int comps = n; 
        vector<int> parent(stones.size());
        iota(parent.begin(),parent.end(),0);
        vector<int> size(stones.size(),1);
        for(int i = 0 ; i<stones.size()-1; i++){
            for(int j = i+1; j <stones.size(); j++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    if(unite(i,j,parent,size))
                        comps--;
        }
        return n - comps;
    }
};