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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == NULL || headB == NULL) return NULL;

        int A_Size = 0;
        int B_Size = 0;

        ListNode * pointerA = headA;
        ListNode * pointerB = headB;

        while(pointerA != NULL || pointerB != NULL) {
        	if(pointerA != NULL) {
        		pointerA = pointerA -> next;
        		A_Size++;
        	}
        	if(pointerB != NULL) {
        		pointerB = pointerB -> next;
        		B_Size++;
        	}        	
        }

        pointerA = headA;
        pointerB = headB;

        while(A_Size != B_Size) {
        	if(A_Size > B_Size) {
        		pointerA = pointerA -> next;
        		A_Size--;
        	}
        	if(B_Size > A_Size) {
        		pointerB = pointerB -> next;
        		B_Size--;
        	}
        }

        while(pointerA != pointerB) {
        	pointerA = pointerA -> next;
        	pointerB = pointerB -> next;
        }

        return pointerA;
    }
};