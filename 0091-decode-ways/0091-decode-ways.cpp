class Solution {
public:
//--------------Memoization------------------------------
    // int helper(int i, string &s, vector<int> &dp){
    //     if (i == s.length()) return 1;
    //     if (s[i] == '0') return 0;    
    //     if (dp[i] != -1) return dp[i];

    //     int ans = helper(i + 1, s, dp);
        
    //     if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
    //         ans += helper(i + 2, s, dp); 
    //     }

    //     return dp[i] = ans;
    // }
//-----------------------------------------------------------------------------


    int numDecodings(string s) {
        if (s.empty()) return 0;
        if(s[0]=='0') return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        // return helper(0, s, dp);
        dp[0]=1;
        dp[1]=1;
        for(int i = 2;i<= n;i++){
            
           if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};