/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head; // 2 pointer ek slow ek fast fast wala 2 step age jayega slow wala ek baar agr wapas mile kbhi toh cycle hai nhi toh nhi

        //single element ya null mein true ayega
        if(head==NULL || head->next ==NULL) return false;
        while(slow!=NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL) fast = fast->next;
            slow = slow->next;

            if(slow==fast) return true; // hare and rabbit soln
        }
        return false; 
    }
};