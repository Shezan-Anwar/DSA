class Solution {
public:
    bool hasPath(int curr, int target, int parent,vector<vector<int>>& adj,vector<bool>& visited) {
        if (curr == target) return true;
        visited[curr] = true;

        for (int neighbor : adj[curr]) {
            if (neighbor == parent) continue;
            if (!visited[neighbor]) {
                if (hasPath(neighbor, target, curr, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n + 1, false);
            if (hasPath(u, v, 0, adj, visited)) {
                return edge; 
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};