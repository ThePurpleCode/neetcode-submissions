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
    ListNode* middlenode(ListNode* head){
        ListNode* slow =head;
        ListNode* fast = head;

        while(fast!=NULL&& fast->next !=NULL){
            fast = fast->next->next; // fast 2 kadam chala
            slow = slow->next; // slow ek kadam chala 
           
        }
        return slow;
    }
    ListNode* reversell(ListNode* head){
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
    void reorderList(ListNode* head) {
        ListNode* midnode = middlenode(head); // mid node nikalo
        ListNode* mid_ke_age = midnode->next; // midnode ke age ka node yaad rkh lo
        midnode->next = NULL; // midnode tk ll ko tod do;

        ListNode* tail = reversell(mid_ke_age);

        ListNode* pt1= head;
        ListNode* pt2 = tail;

        while(pt1 !=NULL && pt2!= NULL){
            ListNode* temp1 = pt1->next;
            ListNode* temp2 = pt2->next;

            pt1->next = pt2; //pointers interconnect kro
            pt2->next = temp1;

            pt1 = temp1; // dono pointer ko age bdha;
            pt2 = temp2;
        }
        return;

    }
};