/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        if(head==NULL || head->next==NULL || head->next->next == NULL){
            return ans;
        }
        ListNode* l = head;
        ListNode* mid = head->next;
        ListNode* r = head->next->next;
        vector<int> idx;
        int currIdx = 2;
        int maxD=INT_MIN;
        int minD=INT_MAX;
        while(r!=NULL){
            if((l->val > mid->val && mid->val < r->val)||(l->val < mid->val && mid->val > r->val)){
                idx.push_back(currIdx);
            }
            currIdx++;
            l=l->next;
            mid=mid->next;
            r=r->next;
        }
        if(idx.size()<=1){
            return ans;
        }
        maxD = idx[idx.size()-1]-idx[0];
        for(int i = 1; i < idx.size() ; i++){
            minD = min(minD,idx[i]-idx[i-1]);
        }
        ans[0]=minD;
        ans[1]=maxD;
        return ans;
    }
};