class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        vector<int> prefix;
        vector<int> suffix;
        int product = 1;
        for ( int i = 0 ; i < nums.size(); i++){
            if (i == 0){
                prefix.push_back(1);
            }else{
                prefix.push_back(product * nums[i-1]);
                product = prefix[i];
            }
        }
        product = 1;
        reverse(nums.begin(),nums.end());
       for (int i = 0 ; i < nums.size(); i++){
        if(i==0){
            suffix.push_back(1);

        }else{
            suffix.push_back(product * nums[i-1]);
            product = suffix[i];
        }
       }
       reverse(suffix.begin(),suffix.end());
       for (int i = 0 ; i<nums.size();i++ ){
        answer.push_back(prefix[i]*suffix[i]);
       }
        return answer;
    }
};