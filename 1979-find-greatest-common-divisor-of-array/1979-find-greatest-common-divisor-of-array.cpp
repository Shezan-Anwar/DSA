class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(int num : nums){
            maxNum = max(maxNum,num);
            minNum = min(minNum,num);
        }
        return gcd(maxNum,minNum);
    }
};