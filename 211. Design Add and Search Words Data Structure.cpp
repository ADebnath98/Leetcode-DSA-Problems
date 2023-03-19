struct Node{
    Node* links[26];
    bool end = false;

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch){
        links[ch - 'a'] = new Node();
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }

};

class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                node->put(ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n = word.length();
        return searchHelper(0, root, n, word);
    }

    bool searchHelper(int ind, Node* node, int n, string &word){
        if(node == NULL) return false;
        if(ind == n) return node->isEnd();
        for(int i = ind; i < n; i++){
            char ch = word[i];
            if(ch == '.'){
                for(char c = 'a'; c <= 'z'; c++){
                    if(searchHelper(i + 1, node->get(c), n, word)){
                        return true;
                    }
                }
                return false;
            }
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */