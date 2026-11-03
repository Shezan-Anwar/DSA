class Solution {
public:
    int helper(int i, string &s,vector<long long> &dp){
        if(i<=0){
            return 1;
        }
        int num = ((s[i-1]-'0')*10)+(s[i]-'0');
        if(dp[i] != -1){
            return dp[i];
        }
        
        long long single = 0;
        if(s[i]!='0'){
            single = helper(i-1,s,dp);
        }
        long long both = 0;
        if(i>=1 && num<=26 && s[i-1]!='0'){
            both = helper(i-2,s,dp);
        }
        return dp[i] = single + both;

    }
    int numDecodings(string s) {
        int n = s.length();
        if(s[0]=='0'){
            return 0;
        }
        vector<long long> dp(n,-1);
        return helper(n-1,s,dp);
    }
};