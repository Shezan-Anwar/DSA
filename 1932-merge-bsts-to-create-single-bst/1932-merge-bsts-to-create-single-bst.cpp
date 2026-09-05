class Solution {
public:
    bool isValidBST(TreeNode* node, unordered_map<int, TreeNode*>& roots, long long minVal, long long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        if (!node->left && !node->right) {
            auto it = roots.find(node->val);
            if (it != roots.end()) {
                TreeNode* nextTree = it->second;
                roots.erase(it);

                node->left = nextTree->left;
                node->right = nextTree->right;
            }
        }

        return isValidBST(node->left, roots, minVal, node->val) && 
               isValidBST(node->right, roots, node->val, maxVal);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;
        unordered_map<int, int> leaves;

        for (auto root : trees) {
            roots[root->val] = root;
            if (root->left) {
                leaves[root->left->val]++;
            }
            if (root->right) {
                leaves[root->right->val]++;
            }
        }

        TreeNode* mainRoot = nullptr;
        for (auto root : trees) {
            if (leaves.find(root->val) == leaves.end()) {
                if (mainRoot != nullptr) {
                    return nullptr;
                }
                mainRoot = root;
            }
        }

        if (!mainRoot) {
            return nullptr;
        }

        roots.erase(mainRoot->val);

        if (!isValidBST(mainRoot, roots, LLONG_MIN, LLONG_MAX)) {
            return nullptr;
        }

        return roots.empty() ? mainRoot : nullptr;
    }
};