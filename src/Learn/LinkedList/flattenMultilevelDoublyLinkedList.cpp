/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        Node * currNode = head;
        while(currNode != nullptr) {
        	if(currNode -> child != nullptr) {
        		Node * nextInLine = currNode -> next;
        		Node * lowerLevels = flatten(currNode -> child);

        		currNode -> child = nullptr;
        		currNode -> next = lowerLevels;
        		lowerLevels -> prev = currNode;

        		Node * lastChild = lowerLevels;
        		while(lastChild -> next != nullptr) lastChild = lastChild -> next;

        		lastChild -> next = nextInLine;
        		if(nextInLine != nullptr) nextInLine -> prev = lastChild;

        		currNode = nextInLine;
        	}
        	else currNode = currNode -> next; 
        }
        return head;
    }
};