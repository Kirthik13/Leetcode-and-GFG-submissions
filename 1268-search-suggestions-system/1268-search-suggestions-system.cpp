struct node
{
  node* links[26]={NULL};
    bool end=false;
    bool contains(char ch)
    {
        return links[ch-'a'];
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
class Trie
{
    public:
        node* root;
        Trie()
        {
            root=new node();
        }
        void insert(string word)
        {
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
         bool search(string word)
        {
            node* h=root;
            for(int i=0;i<word.size();i++)
            {
                if(!h->contains(word[i]))
                {
                   return 0;
                }
                h=h->get(word[i]);
                
            }
            return h->end;
        }
         bool startswith(string word)
        {
            node* h=root;
            for(int i=0;i<word.size();i++)
            {
                if(!h->contains(word[i]))
                {
                   return 0;
                }
                h=h->get(word[i]);
                
            }
            return true;
        }
    
        
        
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string s) {
        Trie h;
        vector<vector<string>>tot;
        sort(begin(v),end(v));
         h.insert(s);
        for(int i=0;i<s.size();i++)
        {
           string t=s.substr(0,i+1);
            // cout<<"t : "<<t<<endl;
            vector<string>sam;
            for(int j=0;j<v.size();j++)
            {
                if(sam.size()==3) break;
                string s2=v[j];
                string t2=s2.substr(0,i+1);
                if(t2==t)
                { sam.push_back(v[j]);
                }
            }
            tot.push_back(sam);
        }
        return tot;
    }
};