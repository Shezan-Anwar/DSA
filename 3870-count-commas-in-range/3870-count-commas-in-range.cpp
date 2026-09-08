class Solution {
public:
    int countCommas(int n) {
        // if(n/1000==0){
        //     return 0;
        // }    
        int ans = n-1000+1;
        return ans <= 0 ? 0:ans; 
        
    }
};