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
    unordered_map<int, int> inMap;
    int search(vector<int>& io,int left , int right, int val){
        for(int i = left; i <= right;i++){
            if(io[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& io, vector<int>& po, int& pIdx , int left, int right){
         if(left>right){
            return NULL;
         }
         TreeNode* root = new TreeNode(po[pIdx]);
         int iIdx = inMap[po[pIdx]];
         pIdx--;
         root->right = helper(io,po,pIdx,iIdx+1,right);
         root->left = helper(io,po,pIdx,left,iIdx-1);
         

         return root;
    }
    TreeNode* buildTree(vector<int>& io, vector<int>& po) {

        int n = po.size();
        for (int i = 0; i < n; i++) {
            inMap[io[i]] = i;
        }
        int pIdx = n-1;
        return helper(io,po,pIdx,0,n-1);

    }
};