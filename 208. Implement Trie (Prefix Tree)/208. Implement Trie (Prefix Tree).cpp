/*
    Solution
        https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58842/Maybe-the-code-is-not-too-much-by-using-%22next26%22-C%2B%2B
*/

// Define Trie Node.
// The node is a TrieNode pointer list from 'a' to 'z', size 26.
class TrieNode {
public:
    TrieNode(bool b = false) {
        is_word = b;
        memset(next, 0, sizeof(next));
    }

    TrieNode* next[26];
    bool is_word;
};

// Solution class
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }

    // Destructor
    ~Trie() {
        clear(root);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->next[word[i] - 'a'] == nullptr)
            {
                temp->next[word[i] - 'a'] = new TrieNode;
            }
            temp = temp->next[word[i] - 'a'];
        }
        temp->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto temp = find_string(word);
        if (temp != nullptr && (temp->is_word)) {
            return true;
        }
        else {
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto temp = find_string(prefix);
        if (temp != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

private:
    TrieNode* root;     // Root node

    // Find the string is in the trie or not.
    TrieNode* find_string(std::string word) {
        auto temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->next[word[i] - 'a'] != nullptr) {
                temp = temp->next[word[i] - 'a'];
            }
            else {
                temp = nullptr;
                break;
            }
        }
        return temp;
    }

    // Destructor.
    void clear(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != nullptr) {
                clear(root->next[i]);
            }
        }
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */