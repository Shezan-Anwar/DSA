class Solution {
public:
    int romanToInt(string s) {
        int ans = 0 ; 
        int rightVal= 0;
        for(int i = s.length();i >= 0 ; i--){
            int currVal = 0 ;

            switch(s[i]){
                case 'I':currVal = 1;break ;
                case 'V':currVal = 5;break ;
                case 'X':currVal = 10;break ;
                case 'L':currVal = 50;break ;
                case 'C':currVal = 100;break ;
                case 'D':currVal = 500;break ;
                case 'M':currVal = 1000;break ;
            }

            if (currVal < rightVal){
                ans-= currVal;
            }else{
                ans+=currVal;
                rightVal = currVal ;
            }
        }
        return ans;
    }
};