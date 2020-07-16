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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode * oddNode = head;
        ListNode * evenNode = head -> next;
        ListNode * evenEntry = head -> next;

        while(evenNode != nullptr) {
            if(evenNode -> next == nullptr) break;
        	oddNode -> next = evenNode -> next;
        	evenNode -> next = evenNode -> next -> next;
        	oddNode -> next -> next = evenEntry;

        	oddNode = oddNode -> next;
        	evenNode = evenNode -> next;
        }

        return head;
    }
};