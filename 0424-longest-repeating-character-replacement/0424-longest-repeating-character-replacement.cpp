class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0 ; 
        int right = 0 ;
        int maxRep = INT_MIN;
        int maxLen = 0;
        int ans = INT_MIN;
        unordered_map<char,int> m;
        while (right < n ){
            m[s[right]]++;
            maxRep = max(m[s[right]],maxRep);
            while ((right - left +1)-maxRep > k){
                m[s[left]]--;
                left ++;
            }
            maxLen = max(maxLen, right - left + 1);
            right ++;

            
            
        }

        return maxLen;
    }
};