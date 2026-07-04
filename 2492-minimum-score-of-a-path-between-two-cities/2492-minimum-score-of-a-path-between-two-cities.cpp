class Solution {
public:
    void dfs(int u, int& ans,vector<bool> &vis,vector<vector<pair<int,int>>> &adj){
        vis[u]= true;
        for(auto neigh : adj[u]){
            int v = neigh.first;
            int wt = neigh.second;
            ans = min(ans,wt);
            if(!vis[v]){
                dfs(v,ans,vis,adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> adj(n+1);

        for ( auto road : roads){
            int u =road[0];
            int v =road[1];
            int wt =road[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int ans = INT_MAX;
        dfs(1 , ans,vis,adj);
        return ans;
    }
};