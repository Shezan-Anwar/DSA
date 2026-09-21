class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        unordered_map<int, long long> prev_dp;
        
        for (int num : nums) {
            unordered_map<int, long long> curr_dp;
            int val = num % k;
            curr_dp[val]++;
    
            for (const auto& [p_val, count] : prev_dp) {
                int new_val = (1LL * p_val * val) % k;
                curr_dp[new_val] += count;
            }
            for (const auto& [p_val, count] : curr_dp) {
                result[p_val] += count;
            }
            
            prev_dp = move(curr_dp);
        }
        
        return result;
    }
};