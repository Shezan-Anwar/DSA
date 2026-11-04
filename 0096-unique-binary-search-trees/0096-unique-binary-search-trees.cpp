class Solution {
public:
    int helper(int n){
        if (n==0 || n==1){
            return 1;
        }
        int total = 0;
        for(int i =1; i <=n;i++ ){
            int leftST = helper(i-1);
            int rightST = helper(n-i);
            total += leftST * rightST; 

        }
        return total;
    }
    int numTrees(int n) {
        return helper(n);
    }
};