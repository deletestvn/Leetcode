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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node * copy, * currCopy, * currPaste;

        // Step 1: create inter weaved list 
        for(currCopy = head; currCopy != NULL; currCopy = currCopy -> next -> next) {
            // Old List: A --> B --> C --> D
            // Inter Weaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
            currPaste = new Node(currCopy -> val);
            currPaste -> next = currCopy -> next;
            currCopy -> next = currPaste;
        }

        // Step 2: get correct reference nodes for random pointers
        for(currCopy = head; currCopy != NULL; currCopy = currCopy -> next -> next) {
            if(currCopy -> random != NULL) currCopy -> next -> random = currCopy -> random -> next;
        }
        copy = head -> next;

        // Step 3: remove original nodes
        for(currCopy = head; currCopy != NULL; currCopy = currCopy -> next) {
            currPaste = currCopy -> next;
            currCopy -> next = currPaste -> next;
            if(currPaste -> next != NULL) currPaste -> next = currPaste -> next -> next;
        }

        return copy;
    }
};