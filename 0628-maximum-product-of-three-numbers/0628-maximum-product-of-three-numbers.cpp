class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int dig1=INT_MIN,dig2=INT_MIN,dig3=INT_MIN;
        int min1 =INT_MAX, min2=INT_MAX;
        for (int num : nums){
            if(num > dig1 ){
                dig3 = dig2;
                dig2 = dig1;
                dig1 = num;
            }else if(num>dig2){
                dig3 = dig2;
                dig2 = num;
            }else if(num > dig3){
                dig3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        return max(dig1*dig2*dig3,dig1*min1*min2) ;
    }
};