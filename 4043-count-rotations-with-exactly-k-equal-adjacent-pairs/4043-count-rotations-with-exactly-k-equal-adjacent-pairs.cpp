class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int count = 0;
        for(int i = 0 ; i < n; i++){
            int score = 0 ; 
            for(int j = 1 ; j < n ; j++){
                if(s[j-1]==s[j]){
                    score++;
                }
            }
            if(score == k ){
                count++;
            }
            char temp = s[0];
            for(int j = 1; j < n ; j++){
                s[j-1]=s[j];
            }
            s[n-1]=temp;
        }
        return count;
    }
};