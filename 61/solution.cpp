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
        if (head == NULL) return NULL;
        ListNode* cur = head;
        int n = 1;
        while (cur->next != NULL) {
            cur = cur->next;
            n++;
        }
        cur->next = head;
        k %= n;
        for (int i = 0; i < n - k; i++) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};