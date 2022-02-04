struct node{
  node* links[2];
    bool end=false;
    int cw{};
    bool contains(char ch)
    {
        return links[ch-'0'];
    }
    void set(char ch,node* h)
    {
        links[ch-'0']=h;
    }
    node* get(char ch)
    {
        return links[ch-'0'];
    }
    
};
class Trie
{
  public:
    node* root;
    int c{};
    Trie()
    {
        root=new node();
    }
    void insert(string &s)
    {
        node* h=root;
        for(int i=0;i<s.size();i++)
        {
            if(!h->contains(s[i]))
            {
                h->set(s[i],new node());
                c++;
            }
            h=h->get(s[i]);
        }
        h->end=true;
        // h->cw++;
    }
    int search(string &s)
    {
         node* h=root;
        string t;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0'){
                
            
            if(h->contains('1'))
            {
               h=h->get('1'); 
                t.push_back('1');
            }
            else{
                h=h->get('0');
                t.push_back('0');

            }
            
            }
            else{
                if(h->contains('0'))
            {
               h=h->get('0'); 
                        t.push_back('0');

            }
            else{
                h=h->get('1');
                t.push_back('1');

            }
            }
            
        }
        long long int value = std::bitset<32>(t).to_ullong();
        return value;
        
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
        int n=v.size();
       long long int ans=INT_MIN;
        Trie h;
        for(int i=0;i<n;i++)
        {
             string s = bitset<32>(v[i]).to_string();
            // for(auto &j:s)
            // {
                h.insert(s);
            
        }
        for(int i=0;i<n;i++)
        {
            string s = bitset<32>(v[i]).to_string();
           long long int t= h.search(s);
            long long t2=(long long)v[i];
            ans=max(t2^t,ans);

        }
        return ans;
    }
};