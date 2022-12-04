#define ll unsigned long long 
class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        int n=v.size();
        
//         vector<ll int>pre(n);
//         vector<ll int>suf(n);
        
//         pre[0]=v[0];
//         suf[n-1]=v[n-1];
        ll pre{},suf{};
        
        for(auto &i:v) suf+=i;
        
//         for(int i=1;i<n;i++)
//         {
//             pre[i]=pre[i-1]+v[i];
//             suf[n-i-1]=suf[n-i]+v[n-i-1];
            
//         }
        
        
           
        
        // suf.push_back(0);
        
        int minval=INT_MAX;
        int residx=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            pre+=v[i];
            suf-=v[i];
            //int a=floor(pre[i]/(1.0*i+1));

            int a=floor(pre/(1.0*i+1));
            
             int b=0;
            if(i!=n-1){
                 // b=floor(suf[i+1]/(1.0*(n-i-1)));
                 b=floor(suf/(1.0*(n-i-1)));
                
            }
            int ans=abs(a-b);
            
            if(ans<minval)
            {
                minval=ans;
                residx=i;
            }
            else if(ans==minval)
            {
               
                residx=min(i,residx);
            }            
            
        }
        
        
        return residx;
        
    }
};