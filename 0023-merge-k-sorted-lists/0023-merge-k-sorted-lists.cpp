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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            if (a->val > b-> val){
            return true;
        }
        return false;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>, Compare> q;
        for ( ListNode* list : lists){
            if(list != NULL){
                q.push(list);
            }
        }
        ListNode* temp = new ListNode(0);
        ListNode* current = temp;

        while (!q.empty()){
            ListNode* smallest = q.top();
            q.pop();

            current->next = smallest;
            current = current->next;
            if(smallest->next != NULL){
                q.push(smallest->next);
            }

        }
        ListNode* result = temp->next;
        delete temp;
        return result ;
    }
};