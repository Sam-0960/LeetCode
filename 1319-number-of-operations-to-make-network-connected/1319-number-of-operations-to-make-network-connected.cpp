class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node],parent);
    }
    bool unite(int u, int v, vector<int>& parent, vector<int>& rank){
        int a = findPar(u,parent); int b = findPar(v,parent);
        if(a==b) return false;
        if(rank[b] < rank[a]){
            parent[b] = a;
        }
        else if(rank[a] < rank[b]){
            parent[a] = b;;
        }else{
            parent[a] = b;
            rank[b]++;
        }
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int comps = n; int req = 0;
        vector<int> parent(n); vector<int> rank(n,0);
        iota(parent.begin(),parent.end(),0);

        for(int i=0; i<connections.size(); i++){
            if(unite(connections[i][0],connections[i][1],parent,rank)){
                comps--;
                req++;
            }
        }
        int total_edges = connections.size();
        int left = total_edges - req;
        if(left+1 < comps) return-1;
        else return comps-1;
    }
};