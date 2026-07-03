class Solution {
public:
    int manDist(vector<vector<int>>& points , int p1 , int p2){
        return abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int mstCost = 0;
        pq.push({0,0}); // wt,u
        
        while (!pq.empty()){
            auto [wt , node] = pq.top();
            pq.pop();
            if(vis[node]==true){
                continue;
            }
            vis[node]=true;
            mstCost+=wt;
            for(int i = 0 ; i < n ; i++){
                if(!vis[i]){
                    int dist = manDist(points, node , i);
                    pq.push({dist, i});
                }
            }
        }


        return mstCost;

    }
};