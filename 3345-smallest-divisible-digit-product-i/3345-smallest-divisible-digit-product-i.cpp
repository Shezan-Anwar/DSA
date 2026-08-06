class Solution {
public:
    bool isAns(int n, int t){
        int prod = 1;
        while(n>0){
            int rem = n%10;
            prod *= rem;
            n/=10;
        }
        if(prod%t==0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        while(!isAns(n,t)){
           n++; 
        }
        return n;
    }
};