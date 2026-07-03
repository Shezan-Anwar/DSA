class Solution {
public:
    const int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    vector<vector<int>> getThiefDist(vector<vector<int>>& grid , int n){
        vector<vector<int>> thiefDist (n , vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c<n ; c++){
                if (grid[r][c]==1){
                    q.push({r,c});
                    thiefDist[r][c]=0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; i++){
                int nr = r+dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(thiefDist[nr][nc]==INT_MAX){
                        thiefDist[nr][nc] = thiefDist[r][c]+1;
                        q.push({nr,nc});

                    }
                }
            }
            
        }
        return thiefDist ;
    }
    bool isValid( int target , int n , vector<vector<int>> &thiefDist ){
        if(thiefDist[0][0] < target){
            return false;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n , vector<bool>(n , false));
        q.push({0,0});
        vis[0][0]=true;

        while (!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if( r == n-1 && c== n-1 ){
                return true;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    if( thiefDist[nr][nc]>= target){
                        vis[nr][nc]= true;
                        q.push({nr,nc});
                    }
                }

            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
       int n = grid.size();
       if ( grid[0][0]==1 || grid[n-1][n-1]==1){
        return 0 ;
       }
       vector<vector<int>> thiefDist = getThiefDist(grid , n);
       int low  = 0 ;
       int high = min(thiefDist[0][0], thiefDist[n-1][n-1]);
       int ans = 0 ;
       while(low <= high){
        int mid = low + (high-low)/2;
        if(isValid(mid , n , thiefDist)){
            ans = mid; 
            low = mid+1;

        }else{
            high = mid-1;
        }
        
       }
       return ans;
    }
};