// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
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
        
        }
       bool search(string &s,int n)
        {
            node* h=root;
             for(int i=0;i<n;i++)
            {
                if(!(h->contains(s[i])))
                {
                    // h->put(s[i],new node());
                    return false;
                    
                }
                h=h->get(s[i]);
            }
            return true;
            
        }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie h;
        vector<vector<string>>tot;
        map<string,int>m;
       for(int i=0;i<n;i++)
       {
           m[contact[i]]++;
       }
        // sort(contact,contact+n,[](string a,string b)
        // {
        //     if(a.size()==b.size()){
        //         return a<b;
        //     }
        //     return a<b;
        // });
        // for(int i=0;i<n;i++)
        // {
        for(int i=1;i<=s.size();i++)
        {
            string k1=s.substr(0,i);
            h.insert(k1);
            vector<string>v2;
            int f=0;
            for(auto &j:m){
                string k=j.first;
                if(h.search(k,k1.size())){
                v2.emplace_back(k);
                f=1;
                }
            }
            if(!f){
            
                v2.emplace_back("0");
                
            }
            tot.emplace_back(v2);
        }
        return tot;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends