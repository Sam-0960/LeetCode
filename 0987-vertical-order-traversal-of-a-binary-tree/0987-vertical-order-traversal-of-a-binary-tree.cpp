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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n = q.size();
            for(int i=0 ; i<n ; i++){
                auto curr = q.front();
                q.pop();
                int vert = curr.second.first , hor = curr.second.second;
                if(curr.first->left){
                    q.push({curr.first->left,{vert+1,hor-1}});
                }if(curr.first->right){
                    q.push({curr.first->right,{vert+1,hor+1}});
                }
                mp[hor][vert].insert(curr.first->val);
            }
        }

        for(auto x:mp){
            vector<int> nodes;
            for(auto y: x.second){
                for(auto z : y.second) 
                    nodes.push_back(z);
            }   
            ans.push_back(nodes);
        }
        return ans;
    }
};