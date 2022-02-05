// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

struct node{
  node* links[26];
  bool end=false;
  int cp{};
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
                h->cp++;
            }
            h->end=true;
        
        }
       string search(string &s)
        {
            node* h=root;
            int n=s.size();
            string k;
             for(int i=0;i<n;i++)
            {
                
                h=h->get(s[i]);
                k.push_back(s[i]);
                if(h->cp==1)
                {
                    
                    break;
                }
            }
            return k;
            
        }
};
class Solution
{
    
    public:
    vector<string> findPrefixes(string v[], int n)
    {
        //code here
        vector<string>tot;
        Trie h;
        for(int i=0;i<n;i++)
        {
            h.insert(v[i]);
        }
        for(int i=0;i<n;i++)
        {
        
            string k=h.search(v[i]);
            tot.emplace_back(k);
        }
        
        return tot;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends