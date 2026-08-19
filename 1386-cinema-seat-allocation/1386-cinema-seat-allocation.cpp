class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> resMap;
        for(auto seat :  reservedSeats ){
            int row = seat[0];
            int col = seat[1];
            if(resMap.find(row)==resMap.end()){
                resMap[row]= vector<bool> (11,false);
            }
            resMap[row][col]=true;
        }

        int ans = (n-resMap.size())*2;

        for(auto [row,reserved] : resMap){
            bool left = !reserved[2] && !reserved[3] && !reserved[4] && !reserved[5];
            bool right = !reserved[6] && !reserved[7] && !reserved[8] && !reserved[9];
            bool middle = !reserved[4] && !reserved[5] && !reserved[6] && !reserved[7];

            if(left && right){
                ans+=2;
            }else if(left || middle || right){
                ans++;
            }
        }

        return ans;
    }
};