 
class Trie {
    class TrieNode {
        public:
        bool isEnd = false;
        TrieNode* arr[26];
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                arr[i] = nullptr;
            }
        }
    };
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* dummy = root;
        for(char c : word) {
            if(dummy->arr[c-'a'] == nullptr) {
                dummy->arr[c-'a'] = new TrieNode();
            }
            dummy = dummy->arr[c-'a'];
        }
        dummy->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* dummy = root;
        for(char c : word) {
            if(!dummy->arr[c-'a']) return false;
            dummy = dummy->arr[c-'a'];
        }
        return dummy->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* dummy = root;
        for(char c : prefix) {
            if(!dummy->arr[c-'a']) return false;
            dummy = dummy->arr[c-'a'];
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
