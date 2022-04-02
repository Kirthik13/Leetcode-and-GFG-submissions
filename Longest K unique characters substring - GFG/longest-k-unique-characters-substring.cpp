// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int>m;
        int ans=INT_MIN,st{};
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            
            while(m.size()>k)
            {
                if(m[s[st]]==1)
                {
                    m.erase(s[st]);
                }
                else{
                    m[s[st]]--;
                }
                st++;
                
            }
            if(m.size()==k){
            ans=max(ans,i-st+1);
            }
        }
        return ans==INT_MIN?-1:ans;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends