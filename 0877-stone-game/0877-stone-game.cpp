class Solution {
public:
int memo[502][502];

    int maxScoreDiff(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i];

        if (memo[i][j] != -1) return memo[i][j];
        int takeLeft  = nums[i] - maxScoreDiff(nums, i + 1, j);
        int takeRight = nums[j] - maxScoreDiff(nums, i, j - 1);

        return memo[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof(memo));
        return maxScoreDiff(piles, 0, n - 1) >= 0;
    }
};