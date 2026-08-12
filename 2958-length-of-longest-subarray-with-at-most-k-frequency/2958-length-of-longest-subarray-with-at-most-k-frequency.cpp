class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0 ,left  = 0 ;
        unordered_map<int,int> m;
        int maxSub = 0;
        while( right < n ){
            m[nums[right]]++;
            while(m[nums[right]]>k && left<right){
                m[nums[left]]--;
                left++;
            }
            maxSub = max(maxSub, right-left+1);
            right++;
        }
        return maxSub;
    }
};