class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int currSum = 0 ;
        for(int i : nums){
            currSum+= i;
            ans = max(ans,currSum);

            if(currSum < 0){
                currSum = 0;

            }
        }
        return ans;
    }
};