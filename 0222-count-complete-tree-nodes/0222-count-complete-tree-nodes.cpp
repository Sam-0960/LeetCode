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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = leftheight(root);
        int right = rightheight(root);
        if(left == right) return (1<<left) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftheight(TreeNode*root){
        int h = 0;
        while(root){
            h++;
            root= root->left;
        }
        return h;
    }
    int rightheight(TreeNode*root){
        int h = 0;
        while(root){
            h++;
            root= root->right;
        }
        return h;
    }
};