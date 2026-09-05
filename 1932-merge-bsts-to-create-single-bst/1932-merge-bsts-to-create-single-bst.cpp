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
    bool isValidBST(TreeNode* node , unordered_map<int,TreeNode*>& roots, int minVal , int maxVal){
        if(!node) return true;

        if(node->val <= minVal || node->val >= maxVal){
            return false;
        }

        if(!node->left && !node->right){
            auto it = roots.find(node->val);
            if(it!=roots.end()){
                TreeNode* nextTree = it->second;
                roots.erase(it);

                node->left = nextTree->left;
                node->right = nextTree->right;
            }

        }

        return isValidBST(node->left,roots,minVal,node->val) && isValidBST(node->right,roots,node->val,maxVal);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> roots;
        unordered_map<int,int> leaves;

        for(auto root:trees){
            roots[root->val] = root;
            if(root->left){
                leaves[root->left->val]++;
            }
            if(root->right){
                leaves[root->right->val]++;
            }
        }

        TreeNode* mainRoot = NULL;
        for(auto root : trees){
            if(leaves.find(root->val)==leaves.end()){
                if(mainRoot != NULL){
                    return NULL;
                }
                mainRoot = root;
            }
        }
        if(!mainRoot){
            return NULL;
        }
        roots.erase(mainRoot->val);
        if(!isValidBST(mainRoot,roots,INT_MIN,INT_MAX)){
            return NULL;
        }

        return roots.empty() ? mainRoot : NULL;
    }
};