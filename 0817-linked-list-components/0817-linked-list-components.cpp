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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());

        int count = 0;
        int consecutive = false;
        ListNode* temp = head;
        while(temp!=NULL){
            if(s.count(temp->val)){
                if(!consecutive){
                    count++;
                    consecutive = true;

                }
                }else{
                    consecutive = false;
                }
                temp=temp->next;
            
        }
        return count;
    }
};