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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr && l2 != nullptr) return l2;
        if(l1 != nullptr && l2 == nullptr) return l1;

        ListNode * sum = new ListNode();
        ListNode * curr = sum;
        ListNode * digit1 = l1;
        ListNode * digit2 = l2;
        int carry = 0;

        while(digit1 != nullptr || digit2 != nullptr || carry != 0) {
        	int x = (digit1 == nullptr) ? 0 : digit1 -> val;
        	int y = (digit2 == nullptr) ? 0 : digit2 -> val;
        	int digitSum = x + y + carry;
        	
        	carry = digitSum / 10;
        	curr -> next = new ListNode(digitSum % 10);

        	curr = curr -> next;
        	if(digit1 != nullptr) digit1 = digit1 -> next;
        	if(digit2 != nullptr) digit2 = digit2 -> next;
        }

    	return sum -> next;
    }
};