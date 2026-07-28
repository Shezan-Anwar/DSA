class Solution {
public:
    int fib(int n) {
        if (n==0 || n==1){
            return n;
        }
        int prev2 = 0;
        int prev1 = 1;
        int result = prev2;
        for(int i=2;i<=n;i++){
            result = prev1 + prev2;
            prev2 = prev1;
            prev1 = result;
        }

        return result;
    }
};