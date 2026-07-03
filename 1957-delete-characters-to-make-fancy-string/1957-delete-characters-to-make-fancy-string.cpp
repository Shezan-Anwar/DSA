class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;
        string result = "";
        result += s[0];
        int count = 0 ;
        for (int i = 1 ; i < s.length(); i++){
            if (s[i] == s[i-1]){
                count ++;
            }else{
                count = 0 ;
            }

            if (count < 2){
                result += s[i];
            }
        }
        return result;
    }
};