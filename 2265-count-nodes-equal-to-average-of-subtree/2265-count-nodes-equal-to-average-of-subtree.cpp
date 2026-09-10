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
    pair<int,int> dfs(TreeNode* node, int& ans){
        if(!node)return {0,0};
        auto left = dfs(node->left,ans);
        auto right = dfs(node->right,ans);
        
        int currSum = node->val + left.first + right.first;
        int currCount = 1+left.second + right.second;

        if(currSum/currCount == node->val) ans++;

        return {currSum, currCount};
    }
    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};