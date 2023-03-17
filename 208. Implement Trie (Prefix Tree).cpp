struct Node{
    Node* link[26];
    bool flag=false;

    //checking if the link for character exists or not
    bool containsKey(char ch) 
    {
        return link[ch-'a']!=NULL;
    }

    //Inserting character in trie
    void put(char ch,Node* node)
    {
        link[ch-'a']=node;
    }

    //marking the end of current word
    void setEnd()
    {
        flag=true;
    }

    //getting the reference trie for the character ch
    Node* get(char ch)
    {
        return link[ch-'a'];
    }

    //check if the current reference trie is the end of word
    bool isEnd(){
        return flag;
    }

};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        //creating dummy node
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);// going to next reference
        }
        node->setEnd(); //setting the current reference as end
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }

        //checking if reference is really an end
        //ex-> word=be and best is in trie so at e we will check if
        // its reference is actually an end or not.
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        //if the loop runs completely then surely the prefix exists
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