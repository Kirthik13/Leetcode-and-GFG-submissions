class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        int n=v.size();
        
        int sum{},maxsf=INT_MIN,minsf=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum<v[i]) sum=v[i];

            maxsf=max(maxsf,sum);
        }
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];

            minsf=min(minsf,sum);
            if(sum>0) sum=0;
            
        }
        
        sum=accumulate(begin(v),end(v),0);
        
        if(sum==minsf) return maxsf; 
        return max(maxsf,sum-minsf);
    }
};