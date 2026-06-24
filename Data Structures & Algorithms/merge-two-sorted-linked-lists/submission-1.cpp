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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* forw1 = NULL;
        ListNode* forw2 = NULL;

        ListNode dummy(0);
        ListNode* pt = &dummy;

        while(curr1 != NULL && curr2 !=NULL){
            if(curr1->val<curr2->val){
                pt->next = curr1; // pt jo dummy ko point kr rha tha uske age curr1 jo dee
                forw1 = curr1->next; // curr1 ko age bdha
                curr1 = forw1;
            }
            else{
                pt->next = curr2;
                forw2 = curr2->next;
                curr2 = forw2;
            }
            //ek baar khtam hua toh pt ko age bdha ... dono(if-else) jagah kr sakte ya toh baad mein ek baar;
            pt = pt->next;

        }
        // ab maan lo ek list khatam hui toh bachi list ki sari daal do
        if(curr1 != NULL){
            pt->next = curr1;
        }
        else{
            pt ->next = curr2;
        }

        return dummy.next; // pt ko age bdhate gaye hai apn pr dummy presevered hai and dummy ka next head hai
    }
};