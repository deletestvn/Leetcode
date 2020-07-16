/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return NULL;

        ListNode * slowPointer = head; 
        ListNode * fastPointer = head;

        int slowCounter = 0;
        int fastCounter = 1;

        while(fastPointer -> next && fastPointer -> next -> next) {
        	slowPointer = slowPointer -> next;
        	fastPointer = fastPointer -> next -> next;  
        	if(slowPointer == fastPointer) {
        		ListNode * entryNode = head;
        		while(slowPointer != entryNode) {
        			slowPointer = slowPointer -> next;
        			entryNode = entryNode -> next;
        		}
        		return entryNode;
        	}     	
        }
        return NULL;
    }
};