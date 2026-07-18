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
    void track(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left) {
                    q.push(current->left);
                    parent[current->left] = current;
                }
                if (current->right) {
                    q.push(current->right);
                    parent[current->right] = current;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        track(root,parent);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> visited;
        int curr = 0;
        visited[target] = true;
        while(!q.empty()){
            int n = q.size();
            if(curr++ == k) break;
            for(int i=0; i<n ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited.find(node->left)==visited.end()){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && visited.find(parent[node]) == visited.end()){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};