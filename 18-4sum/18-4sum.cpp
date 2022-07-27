#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        sort(begin(v),end(v));
        vector<vector<int>>totans;
        int n=v.size();
        
        for(int i=0;i<=n-4;i++)
        {
            if(i>0 and v[i]==v[i-1]) continue;
            for(int j=i+1;j<=n-3;j++)
            {
                if(j!=i+1 and v[j]==v[j-1]) continue;
                int l=j+1,r=n-1;
                
                int el1=v[i],el2=v[j];
                int s2=el1+el2;
                while(l<r)
                {
                     int64_t s=v[l]+v[r];
                    if(target-s==s2)
                    {
                        totans.push_back({el1,el2,v[l],v[r]});
                        
                        while(v[l]==v[l+1] and l+1<r)
                        {
                            l++;
                        }
                        while(v[r]==v[r-1] and l<r-1)
                        {
                            r--;
                        }
                          
                        l++;
                        r--;
                        
                    }
                    else if(target-s>s2 )
                    {
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
            }
        }
        return totans;
    }
};