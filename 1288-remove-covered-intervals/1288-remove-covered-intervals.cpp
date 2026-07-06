class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int>& a,vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int remaining = 0 ; 
        int maxR = INT_MIN;

        for( int i = 0 ; i<intervals.size();i++){
            if(maxR >= intervals[i][1]){
                continue;
            }
            maxR = max(maxR,intervals[i][1]);
            remaining++;
        }
        return remaining;
    }
};