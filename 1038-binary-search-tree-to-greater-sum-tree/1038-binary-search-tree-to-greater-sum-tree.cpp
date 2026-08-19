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
    void helper(TreeNode* root , int& currSum){
        if(root == NULL){
            return;
        }
        
        helper(root->right,currSum);
        root->val = root->val + currSum;
        currSum = root->val;
        helper(root->left,currSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int currSum = 0;
        helper(root,currSum);
        return root;
        
    }
};