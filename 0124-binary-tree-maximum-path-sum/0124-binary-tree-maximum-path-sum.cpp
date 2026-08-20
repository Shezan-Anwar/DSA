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
    int helper(TreeNode* root, int& ans){
        if(root==NULL){
            return 0;
        }
        int leftB = max(0,helper(root->left,ans));
        int rightB = max(0,helper(root->right,ans));

        int curr = root->val + leftB + rightB;

        ans = max(ans,curr);
        return root->val + max(leftB,rightB);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
    }
};