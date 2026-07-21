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
    TreeNode* f(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend,unordered_map<int,int>&mp){
        if(instart > inend || poststart > postend) return nullptr;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mp[postorder[postend]];
        int onleft = inroot - instart;
        root->left = f(inorder,instart,inroot-1,postorder,poststart,poststart+onleft-1,mp);
        root->right = f(inorder,inroot+1,inend,postorder,poststart+onleft,postend-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* root= f(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};