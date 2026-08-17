class Solution {
public:
    int memo[501][501];
    vector<int> prefix;

    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int i, int j) {
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k));
            } else if (rightSum < leftSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j));
            } else {
                maxScore = max(maxScore, leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }

        return memo[i][j] = maxScore;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1);
    }
};