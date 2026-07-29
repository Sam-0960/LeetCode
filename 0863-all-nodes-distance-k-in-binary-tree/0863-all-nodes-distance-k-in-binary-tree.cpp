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
    void track(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        if (root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        mp[root]= nullptr;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        track(root, mp);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        int curr = 0;
        visited[target] = true;
        q.push(target);
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
                if(mp[node] && visited.find(mp[node]) == visited.end()){
                    visited[mp[node]] = true;
                    q.push(mp[node]);
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