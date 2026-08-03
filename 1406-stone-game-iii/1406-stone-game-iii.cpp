class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp1=0,dp2=0,dp3=0;

        for(int i = n-1 ; i >= 0 ;i--){
            int maxDiff = INT_MIN;
            int currTake = 0;

            currTake+=stoneValue[i];
            maxDiff=max(maxDiff,currTake-dp1);

            if(i+1<n){
                currTake+=stoneValue[i+1];
                maxDiff=max(maxDiff,currTake-dp2);
            }
            if(i+2<n){
                currTake+=stoneValue[i+2];
                maxDiff=max(maxDiff,currTake-dp3);
            }

            dp3=dp2;
            dp2=dp1;
            dp1=maxDiff;

            
        }
        int result = dp1;
        if (result > 0) return "Alice";
        if (result < 0) return "Bob";
        return "Tie";
    }
};