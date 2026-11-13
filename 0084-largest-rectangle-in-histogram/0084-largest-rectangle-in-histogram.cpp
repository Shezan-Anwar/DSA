class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> leftb(n,0);
        vector<int> rightb(n,0);
        // right smallest
        for (int i = n-1 ; i >= 0 ; i--){
            while (s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();

            }
            rightb[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()){ // empty stack
            s.pop();
        }

        //left boundary
        for (int i = 0 ; i < n ; i++){
            while ( s.size()> 0 && heights[s.top()]>=heights[i]){
                s.pop();

            }
            leftb[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int ans = 0;
        for ( int i = 0 ; i<n ; i++){
            int width = rightb[i]-leftb[i]-1;
            int area = heights[i] * width;
            ans = max(ans,area);
        }
        return ans;

    }
};