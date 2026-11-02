class Solution {
public:
    vector<vector<int>> dp;
    bool helper(string &s , string &p,int i,int j){
       
       //dono khali
       
       if(i<0 && j<0){
        return true;
       }
       if(j<0){
        return false;
       }
       if(i<0){
            for(int k = 0; k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
       
       if(dp[i][j]!=-1){
        return dp[i][j];
       }

       
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(s, p, i - 1, j - 1);
        }
        if(p[j]=='*'){ 
            return dp[i][j]=helper(s,p,i-1,j)||helper(s,p,i,j-1);
        }

       
       return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {

        int i = s.length();
        int j = p.length();
        
        dp.assign(i,vector<int>(j,-1));
        return helper(s,p,i-1,j-1);

    }
};