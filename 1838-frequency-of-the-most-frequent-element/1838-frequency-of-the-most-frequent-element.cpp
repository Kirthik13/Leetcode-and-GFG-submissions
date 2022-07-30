#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& v, int k) {
        
        sort(begin(v),end(v));
        int n=v.size();

        vector<ll int>prefix(n,0);
        
        prefix[0]=v[0];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+v[i];
        }
        
        int maxi=1;
        
        for(int i=n-1;i>=1;i--)
        {
            int l=0;            
            int r=i;
            
            while(l<r)
            {
                int mid=l+((r-l)/2);
                ll int val=((ll)(i-mid)*(ll)v[i])-(prefix[i-1]-((mid-1>=0)?prefix[mid-1]:0));
                
                if(val<=k)
                {
                    r=mid;
                }
                else{
                    l=mid+1;
                }
                
            }
            
            maxi=max(i-l+1,maxi);
            
            
        }
        
        return maxi;
        
        
    }
};