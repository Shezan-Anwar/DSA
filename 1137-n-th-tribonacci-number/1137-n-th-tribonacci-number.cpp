class Solution {
public:
    int tribonacci(int n) {
        int one = 0; 
        int two = 1;
        int three = 1;
        if(n==0){
            return 0;
        }else if(n==1 || n==2){
            return 1;
        }

        int res;
        for (int i = 2;i<n;i++){
            res = one + two + three;
            one = two;
            two = three;
            three = res;
        }
        return res;
    }
};