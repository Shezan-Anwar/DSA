class Solution {
public:
    bool canReach(int n , vector<vector<pair<int,int>>>& adj , int threshold , long long k){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LONG_MAX);

        dist[0]=0;
        pq.push({0,0});//cost, u

        while(!pq.empty()){
            auto[currCost,u]=pq.top();
            pq.pop();
            if(u == n-1){
                return currCost <= k;
            }

            if(currCost>dist[u]){
                continue;
            }

            for(int i = 0 ; i < adj[u].size();i++){
                auto [v, cost] = adj[u][i];

                if ( cost < threshold ){
                    continue;
                }

                if(currCost + cost < dist[v]){
                    dist[v]= currCost + cost;
                    pq.push({dist[v],v});
                }
            }
        }

        return dist[n-1] <= k;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        vector<vector<pair<int,int>>> adj(n);
        vector<int> uniqueCost ;

        for ( int i = 0 ; i < edges.size() ; i++){ //traverse ke liye adj list create 
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            if(online[u] && online[v]){
                adj[u].push_back({v,cost});
                uniqueCost.push_back(cost);
            }
        }

        sort(uniqueCost.begin(), uniqueCost.end());//binary search ke liye sort
        uniqueCost.erase(unique(uniqueCost.begin(), uniqueCost.end()), uniqueCost.end());

        int low = 0 ;
        int high = uniqueCost.size()-1;
        int ans = -1;
        while(low <= high){
            int mid  = low + (high - low)/2;
            int threshold = uniqueCost[mid];
            if(canReach(n,adj,threshold , k)){
                ans = threshold ;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};