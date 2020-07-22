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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(k == 0 || head == nullptr) return head;

        ListNode * last = head;
        int size = 1;

        while(last -> next != nullptr) {
        	last = last -> next;
        	size++;
        }

        k = k % size;
        if(k == 0) return head;

        int leftLength = size - k;

        ListNode * newEnd = head;

        while(leftLength > 1) {
        	newEnd = newEnd -> next;
        	leftLength--;
        }

        ListNode * newHead = newEnd -> next;

        last -> next = head;
        newEnd -> next = nullptr;

        return newHead;
    }
};