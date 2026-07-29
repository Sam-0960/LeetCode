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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newnode = new TreeNode(val);
            return newnode;
        }
        TreeNode* curr = root;
        int l = 0 , r = 0;
        TreeNode* parent;
        while(curr){
            parent = curr;
            l = r = 0;
            if(val < curr->val){
                curr = curr->left;
                l = 1;
            }else if(val > curr->val){
                curr = curr->right;
                r = 1;
            }
        }
        TreeNode* newnode = new TreeNode(val);
        if(l ) parent->left = newnode;
        else parent->right = newnode;
        return root;
    }
};