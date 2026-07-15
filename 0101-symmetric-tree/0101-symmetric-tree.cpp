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
    bool func(TreeNode* p,TreeNode*q){
        if(p == nullptr && q == nullptr) return true;
        if(p && !q || q && !p) return false;
        if(p->val != q->val) return false;
        return (func(p->left,q->right) && func(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        if(!root->left && !root->right) return true;
        return func(root->left,root->right);
    }
};