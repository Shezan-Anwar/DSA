class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0;
        int minSize = INT_MAX;
        int n = nums.size();
        long long sum = 0 ;
        
        while (right < n){
            sum+=nums[right];
            if(sum>=target){
                while(sum>=target ){
                    minSize= min(minSize,right-left+1);
                    sum-=nums[left];
            
                 left++;
                }
            }
            right++;
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};