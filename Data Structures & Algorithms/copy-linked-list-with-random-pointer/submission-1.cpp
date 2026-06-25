/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution { // ADDNODE FUNC O(N) MEIN JARHA TOH CLONE KRNE MEIN HI O(N^2) JARHA + SC IS O(N)
public: // soln by mapping 
        // create a clone list by next pt and map orignal node with clone node and then clone->random =  map[orignal->random]
    Node* addnode(Node* head , int val){ // at end ek node add kregi
        Node* newNode = new Node(val);

        if(head==NULL) return newNode; // agr empty list hai toh nyi node return kro;

        Node* curr = head;
        while(curr->next!=NULL){ // list traverse kro
            curr = curr->next;
        }
        curr->next = newNode; // end mein nyi node laga do;
        return head;
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* temp = head; // orignal list ko traverse krne ke lie

        while(temp!=NULL){ // next pointer se ek cloned list bana di 
            cloneHead = addnode(cloneHead , temp->val);
            temp = temp->next; // COMPLEXITY IS O(N^2) .. TRY USING TAILNODE IN FUNC
        }
        // ab random pointer add krne hai
        // mapping kr orignal nodes ki clone nodes ke sath

        unordered_map<Node* , Node*> mp;// orignal to clone
        Node* temp1 = head;
        Node* temp2 = cloneHead;

        while(temp1!=NULL && temp2!=NULL){
            mp[temp1] = temp2;
            temp1 = temp1->next;
            temp2= temp2->next;
        }

        // mapping ho gyi ab clone list mein random pointers set kr

        Node* orignal = head;
        Node* clone = cloneHead;

        while(orignal!=NULL){
            clone->random = mp[orignal->random];
            orignal = orignal->next;
            clone = clone->next;           
        }
        return cloneHead;
    }
};
