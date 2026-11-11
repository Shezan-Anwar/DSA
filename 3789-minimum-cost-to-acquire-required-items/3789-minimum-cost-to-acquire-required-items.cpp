class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long separate = (long long)need1 * cost1 + (long long)need2 * cost2;

        long long allBoth = (long long)max(need1, need2) * costBoth;

        long long mix;
        if (need1 < need2) {
            
            mix = (long long)need1 * costBoth + (long long)(need2 - need1) * cost2;
        } else {
            
            mix = (long long)need2 * costBoth + (long long)(need1 - need2) * cost1;
        }

        
        return min({separate, allBoth, mix});
    }
};