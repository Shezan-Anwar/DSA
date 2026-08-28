class Solution {
public:
    bool isPossible(string& half , vector<int> hf){
        for(char ch : half){
            if(--hf[ch-'a']<0) return false;
        }
        return true;
    }
    string makePalindrome(string left, int n, int mid) {
        string full = left;
        if (n % 2 != 0) {
            full += (char)('a' + mid);
        }
        string right = left;
        reverse(right.begin(), right.end());
        return full + right;
    }
    string fillRemaining(vector<int> pool) {
        string res = "";
        for (int i = 0; i < 26; i++) {
           res.append(pool[i], (char)('a' + i));
        }
        return res;
    } 


    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        int odds = 0 ;
        int mid = -1;
        vector<int> halfFreq(26,0);
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]%2!=0){
                odds++;
                mid = i;
            }
            halfFreq[i]=freq[i]/2;
        }
        if(odds > 1 || (n%2==0 && odds>0)){
            return "";
        }
        int m = n/2;
        string left = target.substr(0,m);
        if(isPossible(left,halfFreq)){
            string temp = makePalindrome(left,n,mid);
            if(temp>target){
                return temp;
            }
        }
        for(int i = m-1 ; i >= 0 ; i--){
            string prefix = target.substr(0,i);
            if(!isPossible(prefix,halfFreq)) continue;
            vector<int> tempFreq = halfFreq;
            for(char ch : prefix){
                tempFreq[ch-'a']--;
            }

            for(int c = (target[i] -'a')+1; c<26;c++){
                if(tempFreq[c]>0){
                    tempFreq[c]--;
                    string left = prefix + (char)('a' + c) + fillRemaining(tempFreq);
                    return makePalindrome(left,n,mid);
                }
            }


        }
        return "" ;
    }
};