class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        int maxNum = INT_MIN;
        for (int i = 0 ; i < n ; i++){
            maxNum = max(maxNum,nums[i]);
            prefixGcd[i]=gcd(maxNum,nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int i = 0;
        int j = n-1;
        long long ans = 0 ;
        while (i<j){
            ans+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
        
    }
};