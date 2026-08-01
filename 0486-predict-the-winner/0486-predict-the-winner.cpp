class Solution {
public:
    int memo[21][21];

    int maxScoreDiff(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i];

        if (memo[i][j] != -1) return memo[i][j];
        int takeLeft  = nums[i] - maxScoreDiff(nums, i + 1, j);
        int takeRight = nums[j] - maxScoreDiff(nums, i, j - 1);

        return memo[i][j] = max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        return maxScoreDiff(nums, 0, n - 1) >= 0;
    }
};