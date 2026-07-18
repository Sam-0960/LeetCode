/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == root || q == root ) return root;
        TreeNode* lefttree = lowestCommonAncestor(root->left, p , q);
        TreeNode* righttree = lowestCommonAncestor(root->right, p , q);
        if(!lefttree) return righttree;
        else if(!righttree) return lefttree;
        else return root;
    }
};