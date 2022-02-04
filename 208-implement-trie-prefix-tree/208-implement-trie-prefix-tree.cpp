struct node{
  node* links[26]={0};
    bool end=false;
    
    bool contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void set(char ch,node* h)
    {
        links[ch-'a']=h;
    }
    node* get(char ch)
    {
        return links[ch-'a'];
    }
    
};
class Trie {
public:
    node* root;
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* h=root;
        for(int i=0;i<word.size();i++)
        {
            if(!h->contains(word[i]))
            {
                h->set(word[i],new node());
            }
            h=h->get(word[i]);
        }
        h->end=true;
    }
    
    bool search(string word) {
        node* h=root;
        for(int i=0;i<word.size();i++)
        {
            if(!h->contains(word[i]))
            {
                // h->set(word[i],new node());
                return false;
            }
            h=h->get(word[i]);
        }
        return h->end;
    }
    
    bool startsWith(string word) {
        node* h=root;
        for(int i=0;i<word.size();i++)
        {
            if(!h->contains(word[i]))
            {
                // h->set(word[i],new node());
                return false;
            }
            h=h->get(word[i]);
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