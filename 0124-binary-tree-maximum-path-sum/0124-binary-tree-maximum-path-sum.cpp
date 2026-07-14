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
    int maxi = INT_MIN;
    int func(TreeNode* root){
        if(root == nullptr) return 0;
        int leftsum = max(0,func(root->left));
        int rightsum = max(0,func(root->right));
        maxi = max(maxi, leftsum+rightsum+ root->val);
        return max(leftsum,rightsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        int c = func(root);
        return maxi;
    }
};