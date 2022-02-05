// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
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
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& v) {
        //code here
        vector<vector<string>>tot;
        unordered_map<string,vector<string>>m;
        // Trie h;
        for(int i=0;i<v.size();i++)
        {
            string k=v[i];
            sort(k.begin(),k.end());
            // h.insert(k);
            m[k].emplace_back(v[i]);
            
            
        }
        for(auto i:m)
        {
           tot.emplace_back(i.second);
        }
        return tot;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends