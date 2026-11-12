class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int currI = 1;
        int currD = 1;
        for(int i = 1 ; i < nums.size();i++){
            if(nums[i]>nums[i-1]){
                currI++;
                inc = max(inc,currI);
            }else{
                currI=1;
            }
            if(nums[i]<nums[i-1]){
                currD++;
                dec = max(dec,currD);
            }else{
                currD=1;
            }
        }
        return max(inc,dec);
    }
};