class Solution {
public:
    void dfs(int i , vector<vector<int>>& isConnected , vector<bool> &vis){ // normal dfs logic to visit connected vertices
        vis[i]= true ;
        for (int j = 0 ; j < isConnected[i].size() ; j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j, isConnected , vis);

            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0 ;
        int n = isConnected.size();
        vector<bool> vis(n,false);
        for (int i = 0 ; i < n ; i++){
            if(!vis[i]){    // every unvisited vertex adds up to a new province
                dfs(i , isConnected , vis ); // check krke update krdenge vertex ko 
                ans++; // ans me add
            }
        }
        return ans;
    }
};
