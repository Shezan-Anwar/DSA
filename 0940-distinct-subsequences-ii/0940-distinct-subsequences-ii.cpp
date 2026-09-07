class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        vector<int> last(26,0);
        long long total = 0;

        for(char ch : s){
            int idx = ch-'a';
            long long prev = last[idx];
            long long curr = (total +1)%mod;

            total = (total + curr - prev +mod)%mod;
            last[idx]=curr;
        }
        return total;
    }
};