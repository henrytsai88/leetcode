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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow->next);
        slow->next = NULL;
        while (l2 != NULL) {
            ListNode* tmp = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
            l2 = tmp;
        }
    }
};