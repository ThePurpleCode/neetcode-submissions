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

class Solution {  // TC O(N) ... mp mein jo store kr rha tha ab real pointers laga like orginal ko clone se rea mein mp kr(map use nhi krna)
public:
    Node* addNodeAtTail(Node* &head, Node* &tail , int val){ // ye O(1) mein add krega node
        Node* newNode = new Node(val);

        if(head==NULL){
            head = newNode;
            tail=newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        // clone list bana le normal next se
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp!=NULL){ // O(N) mein cloned list bana dega
            addNodeAtTail(clonehead,clonetail , temp->val);
            temp = temp->next;
        }

        // cloned list hai ab ek doosre ko connect kr ---- head->clonehead-> head ka orignal next -> clone ka orignal next ....

        temp = head;
        Node* clonetemp = clonehead;

        while(temp!=NULL&& clonetemp!= NULL){
            Node* nxt = temp->next;
            temp->next = clonetemp;

            Node* clonenxt = clonetemp->next;
            clonetemp->next= nxt;

            temp = nxt;
            clonetemp = clonenxt;
        }

        Node* curr = head;  // coping random pointer draw krke dekh 
        while(curr!=NULL){
            if(curr->next != NULL){
                if(curr->random != NULL){
                    curr->next->random = curr->random->next; 
                }
                else{ // curr->random == NULL
                    curr->next->random = NULL; // NULL == curr->random
                }
            }             
            curr = curr->next->next;
        }
        // ab jo 2 list jode the usko undo kro

        temp = head;
        clonetemp = clonehead;

        while(temp!= NULL && clonetemp!=NULL){
            temp->next = clonetemp->next;
            temp = temp->next;
            
            if(temp!=NULL){
                clonetemp->next = temp->next;
            }            
            clonetemp= clonetemp->next;
        }
        return clonehead;
    }
};