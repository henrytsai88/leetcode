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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (true) {
            if (list1 == NULL && list2 == NULL) break;
            else if (list1 != NULL && list2 == NULL) {
                cur->next = list1;
                list1 = list1->next;
            }
            else if (list1 == NULL && list2 != NULL) {
                cur->next = list2;
                list2 = list2->next;
            }
            else {
                if (list1->val < list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                }
                else {
                    cur->next = list2;
                    list2 = list2->next;
                }
            }
            cur = cur->next;
        }
        return head->next;
    }
};