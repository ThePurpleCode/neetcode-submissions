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

class Solution { // TC O(N) SC O(N) BETTER THAN ADDNODE FUNC
public:// MAPPING KA AUR EK TARIKA ADDNODE FUNC KI JAROORAT NHI
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        unordered_map<Node* , Node*> mp; // mp of orignal node to clone node
        Node* cloneHead = NULL;

        Node* curr = head;
        while(curr!=NULL){ // naye nodes banake map kr diya 
            mp[curr] = new Node(curr->val);
            curr=curr->next;
        }
        cloneHead = mp[head]; // cloneHead = map[head] kr diya
        // ab pointers laga next and random

        Node* orignal = head;
        while(orignal!=NULL){
            //mp[orignal] = clone
            // clone->next = orignal->next;
            // clone ->random = orignal->random;

            mp[orignal]->next = mp[orignal->next]; // clone ke nodes ko clone ke hi nodes se jodna hai
            mp[orignal]->random = mp[orignal->random];
            orignal = orignal->next;// orignal ko age bdha
        }
        return cloneHead;
    }
};