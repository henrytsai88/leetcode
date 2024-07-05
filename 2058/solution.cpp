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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 0, minDist = INT_MAX, maxDist = 0, prevCriticalPoint = -1;
        while (head && head->next && head->next->next) {
            int prev = head->val, cur = head->next->val, next = head->next->next->val;
            if (cur > prev && cur > next || cur < prev && cur < next) {
                if (prevCriticalPoint != -1) {
                    minDist = min(minDist, i - prevCriticalPoint);
                    maxDist += i - prevCriticalPoint;
                }
                prevCriticalPoint = i;
            }
            head = head->next;
            i++;
        }
        if (maxDist > 0) {
            return {minDist, maxDist};
        }
        return {-1, -1};
    }
};