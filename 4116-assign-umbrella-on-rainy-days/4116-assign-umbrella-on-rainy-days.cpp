class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> answer(n,"None");
        int alice = 0;
        int bob = 0;

        for(int i = 0 ; i< n;i++){
            bool A = (i<n-1 && rain[i]==1 && rain[i+1]==1);
            bool B = (rain[i]==1);
            if(A && B){
                if(alice<=bob){
                    answer[i]="Alice";
                    alice++;
                }else{
                    answer[i]="Bob";
                    bob++;
                }
            }else if(A){
                answer[i]="Alice";
                alice++;
            }else if(B){
                answer[i]="Bob";
                bob++;
            }
        }
        
        return answer;
    }
};