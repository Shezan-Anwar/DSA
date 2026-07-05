class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
       int n = board.size();
        long long Mod = 1e9 + 7;
        
        vector<vector<int>> maxSum(n, vector<int>(n, -1));
        vector<vector<int>> paths(n, vector<int>(n, 0));

        maxSum[0][0] = 0;
        paths[0][0] = 1;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
               
                if ((r == 0 && c == 0) || board[r][c] == 'X') {
                    continue;
                }

                int currentCellVal = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
                int bestPrevSum = -1;
                long long bestPrevPaths = 0;

                int prevCells[3][2] = {{r - 1, c}, {r, c - 1}, {r - 1, c - 1}};

                for (int i = 0; i < 3; ++i) {
                    int pr = prevCells[i][0];
                    int pc = prevCells[i][1];

                    if (pr >= 0 && pc >= 0 && maxSum[pr][pc] != -1) {
                        if (maxSum[pr][pc] > bestPrevSum) {
                            bestPrevSum = maxSum[pr][pc];
                            bestPrevPaths = paths[pr][pc];
                        } else if (maxSum[pr][pc] == bestPrevSum) {
                            bestPrevPaths = (bestPrevPaths + paths[pr][pc]) % Mod;
                        }
                    }
                }

                if (bestPrevSum != -1) {
                    maxSum[r][c] = bestPrevSum + currentCellVal;
                    paths[r][c] = bestPrevPaths;
                }
            }
        }     

        int ansSum = maxSum[n-1][n-1];
        int ansCount = paths[n-1][n-1];
        
        if (ansSum == -1) {
            return {0, 0};
        }

        return {ansSum, ansCount};
       
    }
};