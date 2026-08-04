class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int prev){
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
            auto [dx,dy] = q.front();
            q.pop();

            if(dx-1 >= 0 && image[dx-1][dy] == prev){
                image[dx-1][dy] = color;
                q.push({dx-1,dy});
            } 
            if(dy-1 >= 0 && image[dx][dy-1] == prev){

                image[dx][dy-1] = color;
                q.push({dx,dy-1});
            } 
            if(dx+1 <image.size() && image[dx+1][dy] == prev){
                image[dx+1][dy] = color;
                q.push({dx+1,dy});
            } 
            if(dy+1 <image[0].size() && image[dx][dy+1] == prev){
                image[dx][dy+1] = color;
                q.push({dx,dy+1});
            } 
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(prev == color) return image;
        bfs(image,sr,sc,color,prev);
        return image;
    }
};