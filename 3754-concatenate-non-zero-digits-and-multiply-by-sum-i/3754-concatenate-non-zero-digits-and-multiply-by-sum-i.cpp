class Solution {
public:
    long long sumAndMultiply(int n) {
        int place = 1;
        int temp = n;
        long long newNum = 0;
        long long sum = 0 ;
        while(temp>0){
            int rem = temp%10;
            
            if (rem != 0){
                newNum += rem*place;
                place*=10;
                sum+=rem;
            }
            temp /= 10;
        }
        return sum*newNum;
    }
};