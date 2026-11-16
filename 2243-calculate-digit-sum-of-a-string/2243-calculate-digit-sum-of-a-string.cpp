class Solution {
public:
    
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp = "";
            for (int i = 0; i < s.size(); i += k) {
                string curr = s.substr(i, k);
                int sum = 0;
                for (char c : curr) {
                    sum += c - '0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};