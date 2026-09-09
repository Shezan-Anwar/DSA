class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i<m;i++){
            minHeap.push(nums1[i]);
        }
        for(int j = 0; j<n;j++){
            minHeap.push(nums2[j]);
        }
        int i = 0;
        while(!minHeap.empty()){
            nums1[i] = minHeap.top();
            minHeap.pop();
            i++;
        }
    }
};