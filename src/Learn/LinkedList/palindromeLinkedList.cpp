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
    bool isPalindrome(ListNode* head) {
    	if(head == nullptr || head -> next == nullptr) return true;

        ListNode * slowPointer = head;
        ListNode * fastPointer = head -> next;

        while(fastPointer && fastPointer -> next && fastPointer -> next -> next) {
        	slowPointer = slowPointer -> next;
        	fastPointer = fastPointer -> next -> next;
        }

        fastPointer = fastPointer -> next == nullptr ? slowPointer -> next : slowPointer -> next -> next;

        // Reverse first half
        ListNode * stopNode = slowPointer -> next;
        ListNode * currNode = head;
        ListNode * prevNode = stopNode;      

        while(currNode != stopNode) {
			ListNode* tempNode = currNode -> next;
    		currNode -> next = prevNode;
    		prevNode = currNode;
    		currNode = tempNode;
        }

        // Test is palindrome
        while(fastPointer != nullptr) {
        	if(fastPointer -> val != slowPointer -> val) return false;
        	fastPointer = fastPointer -> next;
        	slowPointer = slowPointer -> next;
        }

        return true;
    }
};