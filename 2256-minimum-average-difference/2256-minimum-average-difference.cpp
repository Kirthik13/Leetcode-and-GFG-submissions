#define ll unsigned long long 
class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        int n=v.size();
        
        vector<ll int>pre(n);
        vector<ll int>suf(n);
        
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        
        
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+v[i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+v[i];
        }        
        
        suf.push_back(0);
        
        int minval=INT_MAX;
        int residx=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int a=floor(pre[i]/(1.0*i+1));
            
            // cout<<"a : "<<a<<endl;
             int b=0;
            if(i!=n-1){
                 b=floor(suf[i+1]/(1.0*(n-i-1)));
            }
            // cout<< a<<" "<<b<<endl;
            int ans=abs(a-b);
            
            if(ans<minval)
            {
                minval=ans;
                residx=i;
                // residx=min(i,residx);
            }
            else if(ans==minval)
            {
                // minval=ans;
                // residx=i;
                residx=min(i,residx);
            }            
            
        }
        
        
        return residx;
        
    }
};