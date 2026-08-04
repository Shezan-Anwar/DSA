class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxN = INT_MIN;
        int minN = INT_MAX;
        unordered_set<int> s;
        for( int i = 0 ; i < nums.size(); i++){
            minN = min(minN,nums[i]);
            maxN = max(maxN,nums[i]);
            s.insert(nums[i]);
        }
        vector<int> ans;
        for ( int i = minN ; i < maxN ; i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};