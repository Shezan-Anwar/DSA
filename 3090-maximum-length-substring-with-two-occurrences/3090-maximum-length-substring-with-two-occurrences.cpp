class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int right = 0 ;
        int left = 0 ;
        int ans = 0;
        unordered_map<char,int> m;
        for(int right = 0 ; right<n ; right++){
            m[s[right]]++;
            while(m[s[right]]>2){
                m[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
    
        }
        return ans;
    }
};