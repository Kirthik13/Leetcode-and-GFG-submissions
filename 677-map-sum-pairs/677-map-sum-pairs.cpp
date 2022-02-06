struct node
{
    node* links[26];
    bool end=false;
    int val{};
    bool contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,node* h)
    {
        links[ch-'a']=h;
    }
    node* get(char ch)
    {
        return links[ch-'a'];
    }
    
};
class Trie
{
public:
    node* root;

  Trie()
  {
        root=new node();

  }
     void fn(string &s,int k)
    {
        node* h=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            // if(!h->contains(s[i]))
            // {
            //     h->put(s[i],new node());
            // }
            h=h->get(s[i]);
           h->val+=k;
            cout<<"h->val : "<<h->val<<endl;
        }
        
        h->end=true;
       
    }
   
    void insert(string &s,int k)
    {
        node* h=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(!h->contains(s[i]))
            {
                h->put(s[i],new node());
            }
            h=h->get(s[i]);
           h->val+=k;
            // cout<<"h->val : "<<h->val<<endl;
        }
        
        h->end=true;
       
    }
    int search(string &s)
    {
        node* h=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            
            if(!h->contains(s[i]))
            {
                
                return 0;
            }
            h=h->get(s[i]);
        }  
        return h->val;
    }
};
class MapSum {
public:
    unordered_map<string,int>m;
    Trie h;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        // if(m.find(key)!=m.end()){
        
            int g=val;
        
        val=val-m[key];
        // cout<<"key : "<<key<<" val : "<<val<<endl;
        //     h.fn(key,val);
        //     m[key]=g;
        // }
        h.insert(key,val);
        m[key]=g;
    }
    
    int sum(string prefix) {
        return h.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */