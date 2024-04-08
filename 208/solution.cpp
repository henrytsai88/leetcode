class Node {
public:
    char data;
    bool isEnd;
    vector<Node*> children;

    Node() {
        isEnd = false;
    }

    Node* findChild(char c) {
        for (Node* child : children) {
            if (child->data == c) return child;
        }
        return NULL;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            Node* next = cur->findChild(c);
            if (next == NULL) {
                next = new Node();
                next->data = c;
                cur->children.push_back(next);
            }
            cur = next;
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            cur = cur->findChild(c);
            if (cur == NULL) return false;
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            cur = cur->findChild(c);
            if (cur == NULL) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */