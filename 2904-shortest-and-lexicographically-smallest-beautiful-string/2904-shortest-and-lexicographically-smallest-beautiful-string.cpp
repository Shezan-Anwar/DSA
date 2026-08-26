class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int oneCount = 0;
        string ans = "";
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                oneCount++;
            }
            while (oneCount == k) {
                while (left <= right && s[left] == '0') {
                    left++;
                }

                string candidate = s.substr(left, right - left + 1);

                if (ans.empty() || candidate.length() < ans.length()) {
                    ans = candidate;
                } else if (candidate.length() == ans.length()) {
                    ans = min(ans, candidate); 
                }
                oneCount--;
                left++;
            }
        }

        return ans;
    }
};