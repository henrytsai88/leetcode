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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode* cur = prev->next;
            prev->next = cur->next;
            cur->next = prev->next->next;
            prev->next->next = cur;
            prev = prev->next->next;
        }
        return dummy->next;
    }
};