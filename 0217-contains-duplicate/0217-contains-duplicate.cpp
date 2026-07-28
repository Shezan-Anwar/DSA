class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums){
            
            s.insert(num);
        }
        if (s.size()<nums.size()){
            return true;
        }
        return false;
    }
};