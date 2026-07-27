class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dig1 = -1,dig2=-1;
        for(int num : nums){
            if(num > dig1){
                dig2 = dig1;
                dig1 = num;
            }else if(num > dig2){
                dig2 = num;
            }
        }
        return (dig1-1)*(dig2-1);
    }
};