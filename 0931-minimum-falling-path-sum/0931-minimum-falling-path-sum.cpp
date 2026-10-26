class Solution {
private:
    int solve(int row, int col, int n,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        
        if (col < 0 || col >= n) {
            return 1e9; 
        }
        if(dp[row][col]!=1e9){
            return dp[row][col];
        }
        
        if (row == n - 1) {
            return matrix[row][col];
        }
        
        int down_left = solve(row + 1, col - 1, n, matrix,dp);
        int down = solve(row + 1, col, n, matrix,dp);
        int down_right = solve(row + 1, col + 1, n, matrix,dp);
        
        return dp[row][col]= matrix[row][col] + min({down_left, down, down_right});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min_sum = 1e9;
        vector<vector<int>> dp(n, vector<int>(n,min_sum));
        for (int col = 0; col < n; ++col) {
            min_sum = min(min_sum, solve(0, col, n, matrix,dp));
        }
        
        return min_sum;
    }
};