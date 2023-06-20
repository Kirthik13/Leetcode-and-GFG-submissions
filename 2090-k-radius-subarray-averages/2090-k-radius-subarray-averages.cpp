class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        int n=v.size();
        
        vector<int>totans(n,-1);
      

        vector<long long>pre(n+1);
        
        pre[0]=v[0];
        // suf[n-1]=v[n-1];
        
        for(int i=0;i<n;i++)
        {
            pre[i+1]=v[i]+pre[i];
        }
      
        
        for(int i=k;i<n-k;i++)
        {
           
            if(i-k<0 or i+k>n) continue;
           
            totans[i]= (pre[i+k+1]-pre[i-k])/(k*2+1);
        }
        return totans;
    }
};