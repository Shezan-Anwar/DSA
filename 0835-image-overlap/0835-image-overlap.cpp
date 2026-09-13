class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> imgOne,imgTwo;
        for(int i = 0 ; i < n ; i ++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    imgOne.push_back({i,j});
                }
                if(img2[i][j]==1){
                    imgTwo.push_back({i,j});
                }
            }
        }
        
        map<pair<int, int>, int> translationCount;
        int maxOverlap = 0;
        
        for (auto p1 : imgOne) {
            for (auto p2 : imgTwo) {
                int rDiff = p2[0] - p1[0];
                int cDiff = p2[1] - p1[1];
                translationCount[{rDiff, cDiff}]++;
                maxOverlap = max(maxOverlap, translationCount[{rDiff, cDiff}]);
            }
        }
        
        return maxOverlap;
    }
};