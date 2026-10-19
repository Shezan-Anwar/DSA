class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> fw(n, vector<int>(n, INF));
        for(int i = 0 ; i < n ; i++){
            fw[i][i]=0;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            fw[u][v]=w;
            fw[v][u]=w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (fw[i][k] + fw[k][j] < fw[i][j]) {
                        fw[i][j] = fw[i][k] + fw[k][j];
                    }
                }
            }
        }
        int minReachable = INF;
        int bestCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && fw[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            if (reachableCount <= minReachable) {
                minReachable = reachableCount;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};