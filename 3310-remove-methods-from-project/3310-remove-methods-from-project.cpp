class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto edge : invocations){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> isSus(n,false);
        queue<int> q;

        q.push(k);
        isSus[k]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto neigh : adj[curr]){
                if(!isSus[neigh]){
                    q.push(neigh);
                    isSus[neigh]=true;
                }
            }
        }
        for(auto node : invocations){
            int u = node[0];
            int v = node[1];

            if(!isSus[u] && isSus[v]){
                vector<int> all(n);
                for(int i = 0 ; i < n ; i++){
                    all[i]=i;
                }
                return all;
            }
        }

        vector<int> res;
        for (int i = 0 ; i < n;i++){
            if(!isSus[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};