class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
     int n = s.length();
        std::vector<int> first(26, -1), last(26, -1);
        
        // Step 1: Record the absolute first and last index of every character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        std::vector<std::string> result;
        int right_bound = -1;
        
        // Step 2: Evaluate potential valid substrings starting at each index
        for (int i = 0; i < n; ++i) {
            // Only start processing if 'i' is the literal first appearance of this character
            if (i != first[s[i] - 'a']) continue;
            
            int end = getValidSubstringEnd(s, i, first, last);
            
            if (end != -1) {
                // If this valid interval starts after our last tracked boundary, it's a new group
                if (i > right_bound) {
                    result.push_back("");
                }
                // Update/overwrite the last entry with the current valid substring
                result.back() = s.substr(i, end - i + 1);
                right_bound = end;
            }
        }
        
        return result;
    }

private:
    int getValidSubstringEnd(const std::string& s, int i, const std::vector<int>& first, const std::vector<int>& last) {
        int end = last[s[i] - 'a'];
        
        // Scan through the current window bounds
        for (int j = i; j <= end; ++j) {
            int c = s[j] - 'a';
            // If any character within this window starts BEFORE our starting index 'i', 
            // then starting a substring at 'i' is completely invalid.
            if (first[c] < i) return -1;
            
            // Expand the window boundary if a character reaches further out
            end = std::max(end, last[c]);
        }
        return end;
    }
};