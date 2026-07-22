/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)  return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                s += '#';
                s += ',';
                continue;
            }
            q.push(node->left);
            q.push(node->right);
            s+= to_string(node->val);
            s += ',';
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream s(data);
        queue<TreeNode*> q;
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#"){
                node->left = nullptr;
            }else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = nullptr;
            }else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));