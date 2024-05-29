/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* cur = head;
        while (cur != NULL) {
            Node* next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        while (cur != NULL) {
            if (cur->random != NULL) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* copy = head->next;
        cur = head;
        while (cur != NULL) {
            Node* next = cur->next->next;
            cur->next->next = next == NULL ? NULL : next->next;
            cur->next = next;
            cur = next;
        }
        return copy;
    }
};