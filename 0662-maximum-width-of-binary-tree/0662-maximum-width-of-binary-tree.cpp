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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxwidth = 0;
        while(!q.empty()){
            int n = q.size();
            long long first, last;
            long long sub = q.front().second;
            for(int i= 0 ; i< n ; i++){
                TreeNode* node = q.front().first;
                long long qmin = q.front().second-sub;
                q.pop();
                if(i == 0) first = 0;
                if(i == n-1) last = qmin;
                if(node->left) q.push({node->left,2*qmin+1});
                if(node->right) q.push({node->right, 2*qmin+2});
            }
            maxwidth = max(maxwidth , last-first+1);
        }
        return (int)maxwidth;
    }   
};