class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int available[10] = {0};
    for (int d : digits) {
        available[d]++;
    }

    int count = 0;

    for (int num = 100; num < 1000; num += 2) {
        int current[10] = {0};
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        current[d1]++;
        current[d2]++;
        current[d3]++;

        if (current[d1] <= available[d1] &&
            current[d2] <= available[d2] &&
            current[d3] <= available[d3]) {
            count++;
        }
    }

    return count;
    }
};