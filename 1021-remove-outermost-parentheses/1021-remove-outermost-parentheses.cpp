class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0 ;
        string ans = "";
        int left = 0;
        for(int right = 0 ; right < s.length();right++){
            if(s[right] =='('){
                bal++;
            }else{
                bal--;
            }
            if(bal == 0){
                ans += s.substr(left+1,right - left-1);
            
                left = right + 1;
            }
        }
        return ans;
    }
};