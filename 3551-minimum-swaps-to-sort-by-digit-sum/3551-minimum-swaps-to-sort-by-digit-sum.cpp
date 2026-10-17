class Solution {
public:
    int digSum(int n){
        int sum = 0;
        while(n!=0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sa = digSum(a);
            int sb = digSum(b);

            if (sa == sb)
                return a < b;

            return sa < sb;
        });

        unordered_map<int, int> target;

        for (int i = 0; i < n; i++) {
            target[sorted[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[nums[i]] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};