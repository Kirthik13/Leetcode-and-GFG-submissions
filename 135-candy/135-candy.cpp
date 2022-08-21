class Solution {
public:
    int candy(vector<int>& v) {
        
        int n=v.size();
        vector<int>curr(n,1);
       
        for(int i=1;i<n;i++)
        {
            if(v[i-1]<v[i])
            {
                curr[i]=curr[i-1]+1;
            }
        }
       
         
        for(int i=n-1;i>0;i--)
        {
            if(v[i-1]>v[i])
            {
                curr[i-1]=max(curr[i]+1,curr[i-1]);
            }
        }
        int sum=accumulate(begin(curr),end(curr),0);
        
        return sum;
        
    }
};