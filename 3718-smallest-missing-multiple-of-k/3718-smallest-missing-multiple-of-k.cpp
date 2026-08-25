class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        int maxN = INT_MIN;
        for(int num : nums){
            if(num%k==0){
                s.insert(num);
            }
        }
        

        int n = nums.size();
        for(int i = 1 ; i <= n ; i++){
            if(s.find(k*i) == s.end()){
                return k*i;
            }
        }
        return k*(n+1);
    }
};