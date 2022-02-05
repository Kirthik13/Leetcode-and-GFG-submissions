struct node{
  node* links[26];
  bool end=false;
  int cw=-1;
  bool contains(char ch)
  {
      return links[ch-'a']!=NULL;
  }
  void put(char &ch,node* h)
  {
      links[ch-'a']=h;
  }
  node* get(char &ch)
  {
      return links[ch-'a'];
  }
  
  
};
class Trie{
    public:
        node* root;
        
        Trie()
        {
            root=new node();
        }
        int insert(string &s,int &idx)
        {
            node* h=root;
            for(int i=0;i<s.size();i++)
            {
                if(!(h->contains(s[i])))
                {
                    h->put(s[i],new node());
                    
                }
                h=h->get(s[i]);
            }
            h->end=true;
            if(h->cw==-1) h->cw=++idx;
            return h->cw;
        
        }
      
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
         vector<vector<string>>tot;
        Trie h;
        int idx=-1;
      
        for(int i=0;i<v.size();i++)
        {
            string k=v[i];
            sort(k.begin(),k.end());
            int newid=h.insert(k,idx);
            
            if(newid==tot.size())
            {
                tot.push_back(vector<string>(1,v[i]));
            }
            else{
                tot[newid].push_back(v[i]);
            }
            
            
            
        }
            return tot;
    }
};