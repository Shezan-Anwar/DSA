class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> pmax(n,INT_MIN);
        vector<int> nmin(n,INT_MAX);
        pmax[0]=nums[0];
        nmin[n-1]=nums[n-1];
        for(int i = 1 ; i < n ; i++){
            pmax[i]=max(pmax[i-1],nums[i]);
        }
        for(int i = n-2 ; i>=0 ; i--){
            nmin[i]=min(nmin[i+1],nums[i]);
        }
        for(int i = 0 ; i < n ; i++){
            if(pmax[i]-nmin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};