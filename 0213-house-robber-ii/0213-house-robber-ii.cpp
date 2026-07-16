class Solution {
public:
    int helperRob(vector<int>& nums , int st , int end){

        int prev1 = nums[st];
        int prev2 = max(nums[st],nums[st+1]);
        int result = prev2;

        for( int i = st+2 ; i <= end ; i ++){
            result = max(prev2 , prev1+nums[i]);
            prev1 = prev2;
            prev2 = result ;
        }
        return result ;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        return max(helperRob(nums,0,nums.size()-2),helperRob(nums,1,nums.size()-1));
    }
};