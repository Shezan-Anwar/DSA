class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefX(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for ( int i = 1; i <n ;i++){
            power10[i]= (power10[i-1]*10) %MOD;
        }

        for (int i = 0  ; i < n ; i++){
            int digit = s[i]-'0';

            prefSum[i+1]=prefSum[i]+digit;
            if(digit != 0){
                prefX[i+1]=((prefX[i]*10)+digit)%MOD;
                nonZeroCount[i+1]= nonZeroCount[i]+1;

            }else{
                prefX[i+1]=prefX[i];
                nonZeroCount[i+1]=nonZeroCount[i];

            }
        }
        vector<int> answers ;
        for ( auto q : queries){
            int l = q[0];
            int r = q[1];
            long long currSum = prefSum[r+1]-prefSum[l];
            int count = nonZeroCount[r+1]-nonZeroCount[l];
            if (count == 0){
                answers.push_back(0);
                continue;
            }
            long long x = (prefX[r+1]-(prefX[l]*power10[count])%MOD + MOD)% MOD;
            long long finalAns = (x * (currSum%MOD))%MOD;
            answers.push_back(finalAns);
        }
        return answers;
        
    }
};