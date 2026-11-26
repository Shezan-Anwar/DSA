class Solution {
public:
    bool canAliceWin(int n) {
        for(int i = 10;i>=0;i--){
            if(i==0){
                return false;
            }

            if(i>n){
                return i%2 == 0 ? false : true;
            }
            n=n-i;
        }
        return true;
    }
};