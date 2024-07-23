/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* dummy = new Node();
        Node* head = root;
        while (head != NULL) {
            Node* parent = head;
            Node* cur = dummy;
            while (parent != NULL) {
                if (parent->left != NULL) {
                    cur->next = parent->left;
                    cur = cur->next;
                }
                if (parent->right != NULL) {
                    cur->next = parent->right;
                    cur = cur->next;
                }
                parent = parent->next;
            }
            head = dummy->next;
            dummy->next = NULL;
        }
        return root;
    }
};