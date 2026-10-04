class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int left = 0, right = 0;
        
    
        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
    
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        
        return max_len;
    }
};