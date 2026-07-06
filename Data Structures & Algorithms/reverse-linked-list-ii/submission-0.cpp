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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;

        while(curr!=NULL){
            forw = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forw;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ct ko 2 pe rakhne se agar shuruwat se hi revrse krna toh error ayega isiliye dummy bana
        int ct =1; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode*curr = dummy;
        while(ct<left){
            curr = curr->next;
            ct++; // abhi curr left ke peeche hai;
        }
        ListNode* middleHead = curr->next;
        ListNode* firstTail = curr;

        while(ct<=right){
            curr= curr->next;
            ct++; // abhi curr middle ke tail pe hai
        }
        ListNode* secondHead = NULL;
        ListNode* middleTail = curr;
        if(curr!=NULL){
            secondHead= curr->next;        
        }
        // ab middle ko todo
        firstTail->next = NULL;
       if(middleTail!=NULL) middleTail->next = NULL;

        middleTail = reverse(middleHead);
        firstTail->next = middleTail;
        if(middleHead!=NULL) middleHead->next = secondHead;

        return dummy->next; // head badal bhi sakta isiliye

    }
};