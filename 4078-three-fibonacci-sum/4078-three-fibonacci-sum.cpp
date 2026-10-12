class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        while(a+b+c<=n){
            if(a+b+c==n){
                return true;
            }
            a=b;
            b=c;
            c=a+b;
        }
        return false;
    }
};