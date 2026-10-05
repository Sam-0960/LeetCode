class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(node == parent[node] ) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    bool unite(int x, int y , vector<int>& parent, vector<int>& rank){
        int a = findPar(x, parent); int b = findPar(y,parent);
        if(a == b) return false;
        if(rank[a] > rank[b] ) parent[b] =a;
        else if(rank[b] > rank[a]) parent[a] = b;
        else{
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        iota(parent.begin(),parent.end(),0);
        vector<int>rank(edges.size()+1,0);
        for(int i=0;i<edges.size(); i++){
            if(!unite(edges[i][0],edges[i][1],parent,rank)){
                vector<int> ans;
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
        }
        return {};
    }
};