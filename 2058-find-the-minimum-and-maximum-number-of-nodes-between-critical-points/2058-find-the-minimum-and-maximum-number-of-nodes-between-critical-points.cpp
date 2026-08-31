class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Fast I/O for competitive programming platforms
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int firstIdx = -1, prevIdx = -1;
        int minD = INT_MAX;
        
        int prevVal = head->val;
        ListNode* curr = head->next;
        int currIdx = 1;

        while (curr && curr->next) {
            int cVal = curr->val;
            int nVal = curr->next->val;

            // Check for critical point
            if ((cVal < prevVal && cVal < nVal) || (cVal > prevVal && cVal > nVal)) {
                if (firstIdx != -1) {
                    minD = min(minD, currIdx - prevIdx);
                } else {
                    firstIdx = currIdx;
                }
                prevIdx = currIdx;
            }

            prevVal = cVal;
            curr = curr->next;
            currIdx++;
        }

        if (firstIdx == -1 || firstIdx == prevIdx) {
            return {-1, -1};
        }

        return {minD, prevIdx - firstIdx};
    }
};