// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends
struct node{
  node* links[2];
  bool end=false;
  int cw{};
  bool contains(int ch)
  {
      return links[ch]!=NULL;
  }
  void put(int &ch,node* h)
  {
      links[ch]=h;
  }
  node* get(int &ch)
  {
      return links[ch];
  }
  
  
};
class Trie{
    public:
        node* root;
        
        Trie()
        {
            root=new node();
        }
        void insert(vector<int> &s)
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
        bool search(vector<int> &s)
        {
            node* h=root;
            for(int i=0;i<s.size();i++)
            {
                // if(!(h->contains(s[i])))
                // {
                //     h->put(s[i],new node());
                    
                // }
                h=h->get(s[i]);
            }
            h->end=true;
            
            
            if(h->cw!=-1)
            {
                // h->cw--;
                h->cw=-1;
                return 1;
            }
            // cout<<"cnt : "<<h->cw<<endl;
            return 0;
        }
       
};
vector<vector<int>> uniqueRow(int v[MAX][MAX],int row,int col)
{
    vector<vector<int>>tot;
    Trie h;
    for(int i=0;i<row;i++)
    {
        vector<int>v2;
    for(int j=0;j<col;j++)
    {
        v2.push_back(v[i][j]);    
    }
        h.insert(v2);
        
    }
    for(int i=0;i<row;i++)
    {
    vector<int>v3;
    for(int j=0;j<col;j++)
    {
        v3.push_back(v[i][j]);    
    }
        if(h.search(v3))
        {
            tot.emplace_back(v3);
        }
        
    }
    return tot;
    
//Your code here
}