class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using Element = tuple<int, int, int>;
        
        int maxVal = INT_MIN;
        int n = nums.size();
        priority_queue<Element,vector<Element>,greater<Element>> mh;
        for(int i = 0 ; i < n ; i++){
            mh.push({nums[i][0],i,0});
            maxVal = max(maxVal,nums[i][0]);
        }
        
        int minRange = INT_MAX;
        vector<int> bestRange = {INT_MIN, INT_MAX};
        
        while(mh.size()==n){
            auto [minVal , k , idx] = mh.top();
            mh.pop();

            int currRange = maxVal - minVal;
            if(currRange<minRange){
                minRange = currRange;
                bestRange = {minVal , maxVal};
            }else if(currRange == minRange && bestRange[0]>minVal){
                bestRange = {minVal , maxVal};
            }

            if(idx+1 < nums[k].size()){
                mh.push({nums[k][idx+1],k,idx+1});
                maxVal = max(maxVal, nums[k][idx+1]);
            }else{
                break;
            }
        }
        return bestRange;
    }
};