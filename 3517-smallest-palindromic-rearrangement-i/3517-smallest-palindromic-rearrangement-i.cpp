class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string left = s.substr(0, n / 2);
        sort(left.begin(), left.end());
        string mid = (n % 2 != 0) ? string(1, s[n / 2]) : "";
        string right = left;
        reverse(right.begin(), right.end());
        
        return left + mid + right;
    }
};