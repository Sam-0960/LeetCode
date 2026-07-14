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
    void func(TreeNode* root, vector<int>& v){
        if(root == nullptr) v.push_back(INT_MIN);
        else{
            v.push_back(root->val);
            func(root->left,v);
            func(root->right,v);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v,u;
        func(p,v);
        func(q,u);
        for(int i = 0; i<v.size(); i++){
            if(v[i]!= u[i]) return false;   
        }
        return true;
    }
};