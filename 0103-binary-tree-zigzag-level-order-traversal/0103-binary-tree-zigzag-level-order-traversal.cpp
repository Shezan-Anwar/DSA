class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : (levelSize - 1 - i);
                currLevel[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(currLevel);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};