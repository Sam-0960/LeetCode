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
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            int prev, curr;
            for(int i=0; i<n ;i++){
                TreeNode* node= q.front();
                q.pop();
                if( i == 0){
                    prev = node->val;
                    if(level%2 == 0 && prev%2 == 0) return false;
                    else if(level%2 == 1 && prev%2 == 1) return false;
                    // no comparision
                }else{
                    // comparion based on level
                    curr = node->val;
                    if(level%2 == 0){
                        if(curr%2 == 0) return false;
                        if(prev >= curr) return false;
                    }else{
                        if(curr%2 == 1) return false;
                        if(prev <= curr) return false;
                    }
                    prev = curr;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++; 
        }
        return true;
    }
};