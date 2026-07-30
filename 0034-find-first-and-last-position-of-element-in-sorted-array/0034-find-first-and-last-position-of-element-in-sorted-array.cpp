class Solution {
public:
    int firstPos(const vector<int>& nums, int target, int st, int end) {
        int first = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return first;
    }

    int lastPos(const vector<int>& nums, int target, int st, int end) {
        int last = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                last = mid;
                st = mid + 1; 
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums, target, 0, nums.size() - 1);
        if (first == -1) {
            return {-1, -1};
        }
        int last = lastPos(nums, target, 0, nums.size() - 1);
        return {first, last};
    }
};