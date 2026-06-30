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
        ListNode* curr1= list1;
        ListNode* curr2 = list2;
        ListNode* forw1= NULL;
        ListNode* forw2 = NULL;
        
        ListNode dummy(0);
        ListNode* pt = &dummy;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val < curr2->val){
                forw1= curr1->next;
                pt->next = curr1;
                curr1= forw1;
            }
            else{
                forw2= curr2->next;
                pt->next = curr2;
                curr2 = forw2;
            }
            pt = pt->next;
        }
        if(curr1!=NULL){
            pt->next =curr1;
        }
        else{
            pt->next = curr2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {;
        int n = lists.size();
        if(n==0) return NULL;
        while(n>1){
            int pos=0;
            for(int i=0;i<n-1;i+=2){
                lists[pos] = mergeTwoLists(lists[i],lists[i+1]);
                pos++;
            }
            if(n%2!=0){
                lists[pos] = lists[n-1];
                pos++;
            } 
            n= pos;
            lists.resize(n);

        }
        return lists[0];
    }
};