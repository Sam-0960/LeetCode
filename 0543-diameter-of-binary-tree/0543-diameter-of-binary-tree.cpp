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
    int currentmax = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void find(TreeNode* root){
        if(root == nullptr) return;
        int left = height(root->left); int right = height(root->right);
        currentmax = max(currentmax, left+right);
        find(root->left);
        find(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        find(root);
        return currentmax;

    }
};