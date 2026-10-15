class Solution {
public:
    int sumCounts(vector<int>& nums) {
      int totalSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                int count = s.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};