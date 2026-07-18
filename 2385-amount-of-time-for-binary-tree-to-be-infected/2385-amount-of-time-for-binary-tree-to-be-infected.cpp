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
    void track(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        while(!q.empty()){
            int n = q.size();
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
        return;
    }
    TreeNode* find(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val)
            return root;
        TreeNode* left = find(root->left, val);
        if(left != nullptr)
            return left;
        TreeNode* right = find(root->right, val);
        if(right != nullptr)
            return right;
        return nullptr;
    }
    int amountOfTime(TreeNode* root, int start) {
        int time = 0;
        unordered_map<TreeNode*,TreeNode*> parent;
        track(root,parent);
        queue<TreeNode*> q;
        TreeNode* target = find( root, start);
        q.push(target);
        unordered_map<TreeNode*,bool> visited;
        visited[target] = true;
        while(!q.empty()){
            int n = q.size();
            time++;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        return time-1;

    }
};