class Solution {
public:
    // int helper(vector<int>& ans,int i,int& count){
    //     if(ans[i]!=0){
    //         return count+=ans[i];
    //     }
    //     count += i%2;
    //     return helper(ans,i/2,count);
    // }
    vector<int> countBits(int n) {
        // vector<int> ans(n+1,0);
        // if(n==0){
        //     return ans;
        // }
        // ans[1]=1;
        // for(int i = 1 ; i <= n ; i++){
        //     int count = 0;
        //     ans[i]=helper(ans,i,count);
        // }
        // return ans;
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};