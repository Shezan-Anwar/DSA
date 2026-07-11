class Solution {
public:
    void dfs(int u , vector<bool> &vis ,vector<vector<int>> &adj, int &vCount , int &degree){
        vis[u]=true;
        vCount++;
        degree += adj[u].size();

        for (int v : adj[u]){

            if (!vis[v]){
                dfs(v,vis,adj,vCount,degree);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0 ; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int ans=0;
        for ( int i = 0 ; i < n ; i++){
            if (!vis[i]){
                int vCount = 0 ;
                int degree = 0;
                dfs(i,vis,adj,vCount,degree);
                if(degree == vCount*(vCount-1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};