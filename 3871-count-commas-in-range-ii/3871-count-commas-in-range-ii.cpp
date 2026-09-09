class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        }

        long long totalCommas = 0;
        if (n <= 999999) {
            return (n - 1000 + 1) * 1;
        } else {
            totalCommas += (999999 - 1000 + 1) * 1;
        }
        if (n <= 999999999) {
            return totalCommas + (n - 1000000 + 1) * 2;
        } else {
            totalCommas += (999999999 - 1000000 + 1) * 2;
        }
        if (n <= 999999999999LL) {
            return totalCommas + (n - 1000000000LL + 1) * 3;
        } else {
            totalCommas += (999999999999LL - 1000000000LL + 1) * 3;
        }
        if (n <= 999999999999999LL) {
            return totalCommas + (n - 1000000000000LL + 1) * 4;
        } else {
            totalCommas += (999999999999999LL - 1000000000000LL + 1) * 4;
        }
        return totalCommas + (n - 1000000000000000LL + 1) * 5;
    }
};