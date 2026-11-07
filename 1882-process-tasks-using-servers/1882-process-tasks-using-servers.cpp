class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            q.push({servers[i], i});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyq;
        long long currTime = 0;
        for (int i = 0; i < m; i++) {
            currTime = max(currTime, (long long)i);
            while (!busyq.empty() && busyq.top().first <= currTime) {
                int idx = busyq.top().second;
                busyq.pop();
                q.push({servers[idx], idx});
            }
            if (q.empty()) {
                currTime = busyq.top().first;
                while (!busyq.empty() && busyq.top().first <= currTime) {
                    int idx = busyq.top().second;
                    busyq.pop();
                    q.push({servers[idx], idx});
                }
            }
            auto [weight, idx] = q.top();
            q.pop();
            ans[i] = idx;
            busyq.push({currTime + tasks[i], idx});
        }

        return ans;
    }
};