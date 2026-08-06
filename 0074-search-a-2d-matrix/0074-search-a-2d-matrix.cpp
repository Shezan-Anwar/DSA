class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int st = 0 ; 
        int end = rows*cols - 1;

        while ( st <= end ){
            int mid = st + (end -st)/2;
            int elem  = matrix[mid / cols][mid%cols];

            if ( elem == target ){
                return true;
            }else if(elem > target ) {
                end = mid -1;
            }else{
                st = mid + 1;
            }

        }
        return false;
    }
};