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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;

        while(curr !=NULL){
            // forward ka track rkho;
            forw = curr->next;
            curr->next = prev; // curr ka next pointer ko prev pointer ke eq bol de
            prev = curr; // prev ko age bdha
            curr = forw; // curr ko age bdha

        }
        return prev;
    }
};