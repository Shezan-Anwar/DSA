class Solution {
public:
    int n;
    vector<int> nextIdx;
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };
    vector<vector<Node>> t;

    int binarySearch(const vector<vector<int>>& intervals, int endPoint) {
        int l = 0;
        int r = n - 1;
        int result = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] > endPoint) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    Node solve(const vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n) {
            return Node{0, {}}; // Base case score must be 0, not -1
        }
        if (t[i][k].score != -1) {
            return t[i][k];
        }

        Node skip = solve(intervals, i + 1, k);
        Node temp = solve(intervals, nextIdx[i], k - 1);
        
        Node take;
        take.score = temp.score + intervals[i][2];
        take.idxs = temp.idxs;
        take.idxs.push_back(intervals[i][3]);
        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            // Lexicographically smaller index array wins on ties
            result = (skip.idxs > take.idxs) ? take : skip;
        }

        return t[i][k] = result;
    }
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            nextIdx[i] = binarySearch(intervals, intervals[i][1]);
        }
        
        int k = 4;
        t.assign(n + 1, vector<Node>(k + 1));
        return solve(intervals, 0, k).idxs;
    }
};