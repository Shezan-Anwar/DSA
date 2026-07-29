class Solution {
public:

    double myPow(double x, int n) {
        long long N  = n;
        if (N<0){
            N=-N;
            x = 1/x;

        }
        double ans = 1.0;
        double currMul = x;

        while (N>0){
            if (N%2==1){
                ans *= currMul;
            }
            currMul*=currMul;
            N/=2;
        }
        return ans;
    }
};