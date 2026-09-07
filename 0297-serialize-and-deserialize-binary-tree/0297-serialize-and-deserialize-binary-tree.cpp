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
    void preOrder(TreeNode* root,string& ans){
        if(root == NULL){
            ans += "_,";
            return;
        }
        ans += to_string(root->val) + ",";
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preOrder(root,ans);
        return ans;
    }
    TreeNode* build(string data,int& idx){
        if (idx >= data.length()) {
            return NULL;
        }

        int commaPos = data.find(',',idx);
        string token = data.substr(idx,commaPos-idx);
        idx = commaPos+1;
        if(token == "_"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = build(data,idx);
        root->right = build(data,idx);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        int idx = 0;
        return build(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));