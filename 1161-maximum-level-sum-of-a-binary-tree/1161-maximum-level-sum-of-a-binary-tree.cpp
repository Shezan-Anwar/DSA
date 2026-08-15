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

    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxL = 1;
        int maxSum = INT_MIN;
        int currL = 1;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            int currSum = 0 ;

            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* node = q.front();
                q.pop();
                currSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currSum > maxSum){
                maxSum = currSum;
                maxL = currL;
            }
            currL++;
        }
        return maxL;
    }
};