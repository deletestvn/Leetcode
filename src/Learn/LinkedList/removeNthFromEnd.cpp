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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head == NULL || head -> next == NULL) return NULL;

        ListNode * slowPointer = head;
        ListNode * fastPointer = head;

        int diff = 0;

        while(fastPointer -> next != NULL) {
        	if(diff != n) diff++;
        	else slowPointer = slowPointer -> next;

        	fastPointer = fastPointer -> next;
        }

        if(diff == n - 1) return head -> next;
        else slowPointer -> next = slowPointer -> next -> next;

        return head;
    }
};