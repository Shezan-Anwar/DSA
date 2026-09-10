class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        // unordered_map<int,int> m;
        // for(int num : nums){
        //     m[num]++;
        // }

        // for(auto [val,freq] : m){
        //     minHeap.push({freq,val});
        //     if(minHeap.size()>k){
        //         minHeap.pop();
        //     }
        // }
        // vector<int> ans;
        // while(!minHeap.empty()){
        //     ans.push_back(minHeap.top().second);
        //     minHeap.pop();
        // }
        // return ans;
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto& [val, freq] : count) {
            buckets[freq].push_back(val);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; --i) {
            for (int val : buckets[i]) {
                ans.push_back(val);
                if (ans.size() == k) break;
            }
        }
        
        return ans;
    }
};