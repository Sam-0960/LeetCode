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
    int ans = INT_MIN;
    int func(TreeNode* root){
        if(root == nullptr) return 0;
        int leftpath = max(0,func(root->left));
        int rightpath = max(0,func(root->right));
        ans = max(ans, root->val+leftpath+rightpath);
        return root->val + max(leftpath,rightpath);
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        int k = func(root);
        return ans;
    }
};