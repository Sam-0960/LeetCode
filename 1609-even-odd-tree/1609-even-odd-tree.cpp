/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        vector<vector<int>> bfs;
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl(n);
            for(int i=0; i<n ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                lvl[i] = node->val;
            }
            bfs.push_back(lvl);
        }
        int flg = 0;
        for(int i = 0; i<bfs.size(); i++){
            if(bfs[i].size() == 1){
                if(flg == 0 ){ 
                    if(bfs[i][0]%2 == 0)return false;
                    flg = 1;
                }
                else{ 
                    if(bfs[i][0]%2 == 1)return false;
                    flg = 0;
                }
                continue;
            }
            else if(flg == 0){
                for(int j=0; j<bfs[i].size()-1 ; j++){
                    if(bfs[i][j]%2 == 0 || bfs[i][j+1]%2 == 0) return false;
                    if(bfs[i][j] >= bfs[i][j+1]) return false;
                }
                flg = 1;
            }else{
                for(int j=bfs[i].size()-1; j>0; j--){
                    if(bfs[i][j]%2 == 1 || bfs[i][j-1]%2 == 1) return false;
                    if(bfs[i][j] >= bfs[i][j-1]) return false;
                }
                flg = 0;
            }
            
        }
        return true;
    }
};