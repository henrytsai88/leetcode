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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* post = cur->next;
            cur->next = prev;
            prev = cur;
            cur = post;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        ListNode* tail = head;
        int i = 0;
        while (tail != NULL) {
            if (++i % k == 0) {
                ListNode* tmp = tail->next;
                tail->next = NULL;
                cur->next = reverse(head);
                cur = head;
                head = tmp;
                tail = head;
            }
            else tail = tail->next;
        }
        cur->next = head;
        return dummy->next;
    }
};