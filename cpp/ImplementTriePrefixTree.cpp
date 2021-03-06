// Source : https://leetcode-cn.com/problems/implement-trie-prefix-tree/
// Author : jkbs487
// Date   : 2020-12-16

/***************************************************************************************************** 
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * Note:
 * 
 * 	You may assume that all inputs are consist of lowercase letters a-z.
 * 	All inputs are guaranteed to be non-empty strings.
 * 
 ******************************************************************************************************/

class Trie {
public:
    typedef struct TrieNode {
        char name;
        bool isEnd;
        vector<TrieNode*> next;
        TrieNode(char c): name(c), isEnd(false), next(vector<TrieNode*>(26, nullptr)){};
    } TrieNode;
 
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode('.');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = head;
        for(auto w : word) {
            if(cur->next[w-'a'] == nullptr)
                cur->next[w-'a'] = new TrieNode(w);
            cur = cur->next[w-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = head;
        for(auto w : word) {
            cur = cur->next[w-'a'];
            if(cur == nullptr)
                return false;
        }
        if(cur->isEnd == false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = head;
        for(auto pre : prefix) {
            cur = cur->next[pre-'a'];
            if(cur == nullptr)
                return false;
        }
        return true;
    }

private:
    TrieNode *head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
