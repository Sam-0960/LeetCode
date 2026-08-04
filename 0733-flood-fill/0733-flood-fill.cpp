class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int prev,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            auto [dx,dy] = q.front();
            q.pop();

            if(dx-1 >= 0 && image[dx-1][dy] == prev && !vis[dx-1][dy] == 1){
                vis[dx-1][dy] = 1;
                image[dx-1][dy] = color;
                q.push({dx-1,dy});
            } 
            if(dy-1 >= 0 && image[dx][dy-1] == prev && !vis[dx][dy-1] == 1){
                vis[dx][dy-1] = 1;
                image[dx][dy-1] = color;
                q.push({dx,dy-1});
            } 
            if(dx+1 <image.size() && image[dx+1][dy] == prev && !vis[dx+1][dy] == 1){
                vis[dx+1][dy] = 1;
                image[dx+1][dy] = color;
                q.push({dx+1,dy});
            } 
            if(dy+1 <image[0].size() && image[dx][dy+1] == prev && !vis[dx][dy+1] == 1){
                vis[dx][dy+1] = 1;
                image[dx][dy+1] = color;
                q.push({dx,dy+1});
            } 
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        vector<vector<int>> vis (image.size(),vector<int>(image[0].size(),0));
        bfs(image,sr,sc,color,prev,vis);
        return image;
    }
};