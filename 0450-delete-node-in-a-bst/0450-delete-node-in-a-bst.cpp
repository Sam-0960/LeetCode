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
    TreeNode* succ(TreeNode* root){
        if(!root) return nullptr;
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* pred(TreeNode* root){
        if(!root) return nullptr;
        while(root->right){
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        TreeNode* curr = root;
        while(curr){
            if(curr->val < key){
                curr->right = deleteNode(curr->right,key);
            }else if(curr->val > key){
                curr->left = deleteNode(curr->left,key);
            }else{
                TreeNode* rep = nullptr;
                if(!curr->left && !curr->right) return nullptr;
                else if(curr->left == nullptr){
                    rep = succ(curr->right);
                    curr->val = rep->val;
                    curr->right = deleteNode(curr->right,rep->val);
                }else if(curr->right == nullptr){
                    rep = pred(curr->left);
                    curr->val = rep->val;
                    curr->left = deleteNode(curr->left,rep->val);
                }else{
                    rep = pred(curr->left);
                    curr->val = rep->val;
                    curr->left = deleteNode(curr->left,rep->val);
                }
            }
            return root;
        }
        return root;
    }
};