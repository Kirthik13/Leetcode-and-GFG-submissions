struct node{
  node* links[26];
  bool end=false;
  int cw{};
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
        void insert(string &s)
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
            h->cw++;
        
        }
       bool search(string &s)
        {
            node* h=root;
            // int i=0;
            int n=s.size();
           
             for(int i=0;i<n;i++)
            {
                if(!(h->contains(s[i])))
                {
                   
                   
                   return 0;
                   
            
            
                    
                }
                h=h->get(s[i]);
            }
           if(h->cw>=1){
           return 1;
           }
           return 0;
          
          
        
            
        }
};
class Solution {
public:
     int dp[300];
   bool fn(string &s,Trie& h)
    {
        if(s.size()==0)
        {
            return dp[s.size()]=1;
        }
            
       if(dp[s.size()]!=-1)
       {
           return dp[s.size()];
       }
        int ch=1;
        string k;
       // cout<<"S : "<<s<<endl;
        for(int i=0;i<s.size();i++)
        {
            k.push_back(s[i]);
            if(h.search(k))
            {
                
                string g=s.substr(i+1);
                if(fn(g,h))
                {
                    return dp[s.size()]=1;
                }
            }
            // else{
            //     return 0;
            // }
            
        }
        return dp[s.size()]=0;
    }
    bool wordBreak(string s, vector<string>& v) {
        Trie h;
        for(int i=0;i<v.size();i++)
        {
            h.insert(v[i]);
        }
        memset(dp,-1,sizeof(dp));
        return fn(s,h);
    }
};