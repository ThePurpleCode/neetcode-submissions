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
    int lllen(ListNode* head){
        ListNode* curr = head;
        int ct=0;
        while(curr!=NULL){
            ct++;
            curr= curr->next;
        }
        return ct;
    }
    void deletenode(ListNode* &head, int n){ // deleting nth node from start // imp // &head kyoki head ko by refrenece pass krna
        if(n==1){
            head = head->next;
        }
        else{
            int ct=1;
            ListNode* curr = head;
            ListNode* prev = NULL;
            while(ct<n){
                prev = curr;
                curr = curr->next;
                ct++;
            }
            // curr wo nth node hai jisko udana hai
            prev->next = curr->next;
            curr->next = NULL;
        }
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lllen(head);
        int nth_from_end = len -n+1;

        deletenode(head , nth_from_end);
        return head;
    }
};