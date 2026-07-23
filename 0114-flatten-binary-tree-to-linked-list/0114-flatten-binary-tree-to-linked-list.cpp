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
    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left) curr = curr->right;
            else{
                TreeNode* node = curr->left;
                while(node->right && node->right != curr) node = node->right;
                if(node->right == nullptr){ 
                    node->right = curr->right;
                    curr->right = curr->left;
                    curr->left = nullptr;
                }
                curr = curr->right;
            }
        }
        return ;
    }
};