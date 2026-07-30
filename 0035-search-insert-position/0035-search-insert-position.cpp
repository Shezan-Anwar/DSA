class Solution {
public:
    int bs(vector<int>& nums, int target,int st,int end){
        while (st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                return bs(nums,target,st,mid-1);
            }else{
                return bs(nums,target,mid+1,end);
            }
        }
        return st;
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
};