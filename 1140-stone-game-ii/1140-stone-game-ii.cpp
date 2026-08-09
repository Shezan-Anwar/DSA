class Solution {
public:
    int dp(int i , int m ,vector<vector<int>>& mem,vector<int>& suffSum , int n ){
        if(i>=n) return 0;
        if(i+2*m >= n) return suffSum[i];
        if(mem[i][m]!=-1) return mem[i][m];

        int maxStone = 0;
        for(int X = 1; X <= 2*m ; X++){
            int oppScore = dp(i+X,max(m,X),mem,suffSum,n);
            int currScore = suffSum[i]-oppScore;
            maxStone = max(maxStone,currScore);
        }
        return mem[i][m]=maxStone;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffSum(n);
        suffSum[n-1]=piles[n-1];
        for(int i = n-2;i>=0;i--){
            suffSum[i] = suffSum[i+1]+piles[i];
        }
        vector<vector<int>> mem(n,vector<int>(n ,-1));
        return dp(0,1,mem,suffSum,n);

    }
};