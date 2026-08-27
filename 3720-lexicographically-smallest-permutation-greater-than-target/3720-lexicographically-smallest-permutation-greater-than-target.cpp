class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        if (target.length() != n) return "";
        
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        int matched = 0;
        while (matched < n && freq[target[matched] - 'a'] > 0) {
            freq[target[matched] - 'a']--;
            matched++;
        }
        
        for (int i = matched; i >= 0; i--) {
            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string res = target.substr(0, i);
                        res += (char)('a' + c);
                        freq[c]--;
                        
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                res += (char)('a' + k);
                                freq[k]--;
                            }
                        }
                        
                        return res;
                    }
                }
            }
            if (i > 0) {
                freq[target[i - 1] - 'a']++;
            }
        }
        return "";
    }
};