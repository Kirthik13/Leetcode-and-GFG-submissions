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
   
    void insert(string &s)
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
           
        }
        
        h->end=true;
       
    }
    int search(string &s,int n)
    {
        node* h=root;
        // cout<<" n : "<<n<<endl;
        // cout<<"s : "<<s<<endl;
        for(int i=0;i<n;i++)
        {
            
            if(!h->contains(s[i]))
            {
                
                return 0;
            }
            h=h->get(s[i]);
        }  
        return 1;
    }
};

class MapSum {
public:
    map<string,int>m;
    MapSum() {

    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string p) {
                        Trie h;

        h.insert(p);
        int c{};
        for(auto &i:m)
        {
            string k=i.first;
            int n=p.size();
            if(k.size()>=n){
            if(h.search(k,n))
            {
                c+=i.second;
            }
            }
        }
        return c;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */