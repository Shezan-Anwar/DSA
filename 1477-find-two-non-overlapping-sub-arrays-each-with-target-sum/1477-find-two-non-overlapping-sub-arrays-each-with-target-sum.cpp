class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n,INT_MAX);
        int left = 0 ;
        int right = 0 ;
        int currSum = 0 ;
        int ans = INT_MAX;
        int minLen = INT_MAX;
        while(right<n){
            currSum+=arr[right];
            
            while(currSum>target && left <= right){
                currSum-=arr[left];
                left++;
            }
            if(currSum==target){
                int currSize = right - left + 1;
                
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, currSize + dp[left - 1]);
                }
                minLen = min(minLen, currSize);
            }
            dp[right]=minLen;
            right++;
        }
        return ans==INT_MAX?-1:ans;
    }
};