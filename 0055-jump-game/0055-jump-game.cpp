class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPossible = 0;
        int n = nums.size();
        for (int i = 0 ; i<n ; i++){
            if(i>maxPossible){
                return false;
            }

            maxPossible = max(maxPossible,i+nums[i]);
            if(maxPossible >= n-1){
                return true;
            }
        }
        return true;
    }
};