class Solution {
public:
    int n;
    int helper(int i,vector<int>& nums,int target,int currSum){
        //base case
        if(i==n){
            if(currSum == target){
                return 1;
            }else{
                return 0;
            }
        }
        int left = helper(i+1, nums,target , currSum + nums[i]);     //left
        int right = helper(i+1, nums,target , currSum - nums[i]);       //right

        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int i = 0;
        n = nums.size();
        return helper(i,nums,target,0);
    }
};