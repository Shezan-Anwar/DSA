class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2;
        int a1 = nums[0];
        int a2 = nums[1];
        while(i<nums.size()){
            if(a1>a2){
                arr1.push_back(nums[i]);
                a1 = nums[i];
            }else{
               arr2.push_back(nums[i]);
                a2 = nums[i]; 
            }
            i++;
        }
        i=0;
        while (i<arr2.size()){
            arr1.push_back(arr2[i]);
            i++;
        }
        return arr1;
    }
};