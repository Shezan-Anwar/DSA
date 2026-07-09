class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int combo = 0 ;
        vector<int> helper(n,0);
        for(int i = 1 ; i < n ;i++){
            if (nums[i]-nums[i-1]>maxDiff){
                combo++;
            }
            helper[i]=combo;
        }
        int s = queries.size();
        vector<bool> ans(s);
        for(int k=0;k<s;k++){
            int i = queries[k][0];
            int j = queries[k][1];
            if (helper[i]==helper[j]){
                ans[k]=true;
            }else{
                ans[k]=false;
            }
        }
        return ans;  
    }
};