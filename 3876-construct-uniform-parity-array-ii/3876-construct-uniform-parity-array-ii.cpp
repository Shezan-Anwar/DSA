class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
    
        int smallestNum = INT_MAX;
        bool allEven = true;
        for(int i = 0 ; i < n;i++){
            if(nums1[i]%2!=0){
                allEven = false;
            }
            smallestNum = min(nums1[i],smallestNum);
        }
        if(allEven){
            return true;
        }
        if(smallestNum%2!=0){
            return true;
        }
        return false;
    }
};