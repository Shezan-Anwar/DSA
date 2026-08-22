class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digSum = 0 ;
        int digPro = 1;
        while (temp>0){
            int dig = temp%10;
            digSum+=dig;
            digPro*=dig;
            temp/=10;
        }
        return n%(digSum+digPro)==0;
    }
};