class TrieNode {
public:
    char data;
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode(char c) {
        data = c;
        isEnd = false;
    }

    TrieNode* findChild(char c) {
        for (TrieNode* child : children) {
            if (child->data == c) return child;
        }
        return NULL;
    }
};

class Solution {
public:
    void insert(string& word, TrieNode* root) {
        TrieNode* cur = root;
        for (char c : word) {
            TrieNode* next = cur->findChild(c);
            if (next == NULL) {
                next = new TrieNode(c);
                cur->children.push_back(next);
            }
            cur = next;
        }
        cur->isEnd = true;
    }
    string search(string& word, TrieNode* root) {
        string res;
        TrieNode* cur = root;
        for (char c : word) {
            TrieNode* next = cur->findChild(c);
            if (next == NULL) {
                return word;
            }
            res += c;
            if (next->isEnd) break;
            cur = next;
        }
        return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode(0);
        for (string word : dictionary) {
            insert(word, root);
        }
        istringstream in(sentence);
        string word, res;
        while (in >> word) {
            res += search(word, root) + ' ';
        }
        res.pop_back();
        return res;
    }
};