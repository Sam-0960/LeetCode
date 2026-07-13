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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }else{
                TreeNode* curr = st.top()->right;
                if(curr == nullptr){
                    curr = st.top();
                    st.pop();
                    ans.push_back(curr->val);
                    while(!st.empty() && curr == st.top()->right ){
                        curr = st.top();
                        st.pop();
                        ans.push_back(curr->val);
                    }
                }else
                    root = curr;
            }
        }
        return ans;
    }
};