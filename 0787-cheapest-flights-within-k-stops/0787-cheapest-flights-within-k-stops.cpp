class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices (n,INT_MAX); 
        prices[src]=0;

        for(int i = 0 ; i <= k; i++){
            vector<int> tempPrice=prices;
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if(prices[u]==INT_MAX){
                    continue;
                }

                if(cost+prices[u]<tempPrice[v]){
                    tempPrice[v]=prices[u]+cost;
                }
            }
            prices = tempPrice;
        }
        return prices[dst]==INT_MAX? -1: prices[dst];
    }
};