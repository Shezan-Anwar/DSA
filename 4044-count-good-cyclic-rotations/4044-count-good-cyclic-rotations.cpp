class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        int count = 0;
        long long total = 0 ;
        for(int i = 0 ; i < n; i++){
            total += nums[i];
        }
        long long lScore = 0;
        for(int i=0; i<half;i++){
            lScore+=nums[i];
        }

        for(int i =0;i<n;i++){
            long long rScore = total - lScore;
            if(lScore>rScore){
                count++;
            }
            lScore+= nums[(i+half)%n]-nums[i];
        }
        return count;
    }
};