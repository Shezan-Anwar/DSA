class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lSum = 0, rSum = 0;
        int ql = 0 , qr = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i<n/2){
                if (num[i]=='?'){
                    ql++;
                    continue;
                }
                lSum+= num[i]-'0';
            }else{
                if (num[i]=='?'){
                    qr++;
                    continue;
                }
                rSum+= num[i]-'0';
            }
        }
        
        return (2 * (lSum - rSum) + (ql - qr) * 9) != 0;
        }
};