// class Solution {
// public:
//     long long solve(int i ,vector<int>& prices, int k,bool ongoing,int type, vector<vector<vector<vector<long long>>>> &dp){
//         if (i == prices.size()) {
//             return ongoing ? -1e15 : 0LL;
//         }
//         if(dp[i][k][ongoing][type]!=-1LL){
//             return dp[i][k][ongoing][type];
//         }

//         long long ans = -1e15;

//         if (!ongoing) {
//             ans = max(ans, solve(i + 1, prices, k, false, 0,dp));

//             if (k > 0) {

//                 ans = max(ans, -1LL * prices[i] + solve(i + 1, prices, k - 1, true, 1,dp));

//                 ans = max(ans, 1LL * prices[i] + solve(i + 1, prices, k - 1, true, 2,dp));
//             }
//         }else{
//             ans = max(ans,solve(i+1,prices,k,true,type,dp));

//             if(type == 1){
//                 ans = max(ans,1LL*prices[i]+solve(i+1,prices,k,false,0,dp));
//             }else{
//                 ans = max(ans,-1LL*prices[i]+solve(i+1,prices,k,false,0,dp));
//             }
//         }
//         return dp[i][k][ongoing][type]=ans;
//     }
//     long long maximumProfit(vector<int>& prices, int k) {
//         int n = prices.size();
//         if(prices.size()==0 || k ==0){
//             return 0;
//         }
//         vector<vector<vector<vector<long long>>>> dp(n,vector<vector<vector<long long>>>(k+1,vector<vector<long long>>(2,vector<long long>(3,-1LL))));
//         return solve(0,prices,k,false,0,dp);
//     }
// };
class Solution {
private:
    static constexpr long long UNVISITED = 4000000000000000000LL;
    static constexpr long long NEG_INF   = -1000000000000000LL;
    int n, K;
    vector<long long> dp;

    inline int idx(int i, int remK, int og, int type) const {
        return (((i * (K + 1) + remK) * 2 + og) * 3 + type);
    }

public:
    long long solve(int i, vector<int>& prices, int remK, bool ongoing, int type) {
        if (i == n) {
            return ongoing ? NEG_INF : 0LL;
        }

        int og = ongoing ? 1 : 0;
        int id = idx(i, remK, og, type);
        if (dp[id] != UNVISITED) {
            return dp[id];
        }

        long long ans = NEG_INF;

        if (!ongoing) {
            ans = max(ans, solve(i + 1, prices, remK, false, 0));

            if (remK > 0) {
                ans = max(ans, -1LL * prices[i] + solve(i + 1, prices, remK - 1, true, 1));
                ans = max(ans,  1LL * prices[i] + solve(i + 1, prices, remK - 1, true, 2));
            }
        } else {
            ans = max(ans, solve(i + 1, prices, remK, true, type));

            if (type == 1) {
                ans = max(ans,  1LL * prices[i] + solve(i + 1, prices, remK, false, 0));
            } else {
                ans = max(ans, -1LL * prices[i] + solve(i + 1, prices, remK, false, 0));
            }
        }

        return dp[id] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = static_cast<int>(prices.size());
        if (n <= 1 || k <= 0) {
            return 0LL;
        }
        K = min(k, n / 2);
        dp.assign((n + 1) * (K + 1) * 2 * 3, UNVISITED);
        return solve(0, prices, K, false, 0);
    }
};