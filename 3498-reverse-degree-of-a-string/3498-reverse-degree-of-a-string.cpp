class Solution {
public:
    int reverseDegree(string s) {
        long long total = 0; 
        for (int i = 0; i < s.length(); ++i) {
            int rev_val = 'z' - s[i] + 1;
            total += 1LL * rev_val * (i + 1);
        }
        return total;

    }
};