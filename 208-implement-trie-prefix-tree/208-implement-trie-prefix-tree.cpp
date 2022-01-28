struct node{
    node* links[26]={0};
    bool flag=0;
    bool contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void setnode(char ch,node* h)
    {
        links[ch-'a']=h;
    }
    node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void setend()
    {
        flag=1;   
    }
    bool isend()
    {
        return flag;
    }
};
class Trie {
private:
            node* root;

public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* h=root;
        for(int i=0;i<word.size();i++)
        {
            if(!(h->contains(word[i]))){
            h->setnode(word[i],new node());
            }
            h=h->getnode(word[i]);
        }
        h->setend();
    }
    
    bool search(string word) {
        node* h=root;
        for(int i=0;i<word.size();i++)
        {
            
            if(!(h->contains(word[i]))) return 0;
            h=h->getnode(word[i]);
        }
        return h->isend();
    }
    
    bool startsWith(string word) {
         node* h=root;
        for(int i=0;i<word.size();i++)
        {
            
            if(!(h->contains(word[i]))) return 0;
            h=h->getnode(word[i]);
        }
        return 1;
    }
};

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */
// struct Node {
//     Node *links[26]; 
//     bool flag = false; 
    
//     bool containsKey(char ch) {
//         return (links[ch - 'a'] != NULL); 
//     }
//     Node* get(char ch) {
//         return links[ch-'a']; 
//     }
//     void put(char ch, Node* node) {
//         links[ch-'a'] = node; 
//     }
//     void setEnd() {
//         flag = true; 
//     }
//     bool isEnd() {
//         return flag; 
//     }
// }; 
// class Trie {
//     private: Node *root; 
// public:
//     /** Initialize your data structure here. */
//     Trie() {
//         root = new Node(); 
//     }
    
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         Node *node = root;
//         for(int i = 0;i<word.size();i++) {
//             if(!node->containsKey(word[i])) {
//                 node->put(word[i], new Node()); 
//             }
//             node = node->get(word[i]); 
//         }
//         node->setEnd(); 
//     }
    
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         Node *node = root; 
//         for(int i = 0;i<word.size();i++) {
//             if(!node->containsKey(word[i])) {
//                 return false; 
//             }
//             node = node->get(word[i]); 
//         }
//         if(node->isEnd()) {
//             return true; 
//         }
//         return false; 
//     }
    
//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         Node *node = root; 
//         for(int i = 0;i<prefix.size();i++) {
//             if(!node->containsKey(prefix[i])) {
//                 return false; 
//             }
//             node = node->get(prefix[i]); 
//         }
//         return true; 
//     }
// };