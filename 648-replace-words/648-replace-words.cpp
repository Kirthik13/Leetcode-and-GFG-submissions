struct node{
  node* links[26];
  bool end=false;
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
    void insert(string s)
    {
        node *h=root;
        for(int i=0;i<s.size();i++)
        {
            if(!(h->contains(s[i])))
            {
                h->put(s[i],new node());
            }
            h=h->get(s[i]);
        }
        h->end=true;
    }
    string search(string s)
    {
        node* h=root;
        string b;
        for(int i=0;i<s.size();i++)
        {
            if(h->end)
            {
                return b;
            }
            if(!(h->contains(s[i])))
            {
                return "";
            }
            h=h->get(s[i]);
            b.push_back(s[i]);
        }
        return b;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dic, string s) {
        string dum,ans;
        stringstream ss(s);
        vector<string>v;
        Trie h;
        while(getline(ss,dum,' '))
        {
            v.push_back(dum);
        }
        for(int i=0;i<dic.size();i++)
        {
            h.insert(dic[i]);
            
           
        }
        for(int i=0;i<v.size();i++)
        {
            string k=h.search(v[i]);
            
            if(k=="")
            {
                ans+=v[i];
            }
            else{
                ans+=k;
            }
            ans.push_back(' ');
        }
        ans.pop_back();
       
        return ans;
    }
};