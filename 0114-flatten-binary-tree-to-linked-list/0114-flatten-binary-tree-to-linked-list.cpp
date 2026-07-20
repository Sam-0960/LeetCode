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
    TreeNode* predecessor(TreeNode* root){
        if(root== nullptr) return nullptr;
        while(root->right){
            root= root->right;
        }
        return root;
    }
    void f(TreeNode* root){
        if(root==nullptr) return;
        if(root->left){
            TreeNode* pred = predecessor(root->left);
            pred->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        f(root->right);;
        return;
    }
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        f(root);
        return;
    }
};