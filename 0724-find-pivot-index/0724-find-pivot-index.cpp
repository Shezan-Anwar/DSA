class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> preSum(nums.size(),0);
        vector<int> suffSum(nums.size(),0);
        int sum = 0 ; 
        for(int i = 1 ; i < nums.size() ; i++){
           sum=sum+nums[i-1];
           preSum[i]=sum;
        }
        sum = 0;
        for(int i = nums.size()-2 ; i >=0 ; i--){
            sum=sum+nums[i+1];
            suffSum[i] = sum;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(preSum[i]==suffSum[i]){
                return i;
            }
        }

    return -1;
    }
};