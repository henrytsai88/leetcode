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

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode(0);
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        return helper(word, root, 0);
    }

    bool helper(string& word, TrieNode* root, int i) {
        if (i == word.size()) return root->isEnd;
        if (word[i] == '.') {
            for (TrieNode* next : root->children) {
                if (helper(word, next, i + 1)) return true;
            }
        }
        else {
            TrieNode* next = root->findChild(word[i]);
            if (next != NULL && helper(word, next, i + 1)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */