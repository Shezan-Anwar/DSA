class Solution {
public:
    bool winnerSquareGame(int n) {
      vector<bool> ans(n+1,false);
      
      for(int i = 1 ;i <= n ; i++){
        int k = 1;
        while ( k*k <= i){
            if(!ans[i-k*k]){
                ans[i]=true;
                break;
            }
            k++;
        }
      }
      return ans[n];
    }
};