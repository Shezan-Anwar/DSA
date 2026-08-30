class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }

        int minId = 0;
        int maxId = 0;
        
        for(int i = 0 ; i < n; i++){
            if (nums[i] < nums[minId]) minId = i;
            if (nums[i] > nums[maxId]) maxId = i;
        }
        int i = min(maxId,minId);
        int j = max(maxId,minId);

        return min({j+1,n-i,(i+1)+(n-j)});
    }
};