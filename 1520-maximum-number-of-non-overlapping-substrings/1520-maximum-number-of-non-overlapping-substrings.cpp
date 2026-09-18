class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
     int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
    
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        vector<string> result;
        int right_bound = -1;
        
        for (int i = 0; i < n; ++i) {
            if (i != first[s[i] - 'a']) continue;
            
            int end = getValidSubstringEnd(s, i, first, last);
            
            if (end != -1) {
                if (i > right_bound) {
                    result.push_back("");
                }
                result.back() = s.substr(i, end - i + 1);
                right_bound = end;
            }
        }
        
        return result;
    }

private:
    int getValidSubstringEnd(const string& s, int i, const vector<int>& first, const vector<int>& last) {
        int end = last[s[i] - 'a'];
        
        
        for (int j = i; j <= end; ++j) {
            int c = s[j] - 'a';
            if (first[c] < i) return -1;

            
            end = max(end, last[c]);
        }
        return end;
    }
};