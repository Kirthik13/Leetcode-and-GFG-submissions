class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
     vector<vector<int>>totans;   
        sort(begin(v),end(v));
        int n=v.size();
        for(int i=0;i<=n-3;i++)
        {
            if(i>0 and v[i-1]==v[i]) continue;
            int l=i+1,r=n-1;
            int el=v[i];
            while(l<r)
            {
                
                if(el+v[l]+v[r]==0)
                {
                    totans.push_back({el,v[l],v[r]});
                    
                    
                    while(v[l]==v[l+1] and l+1<r) l++;
                    while(v[r]==v[r-1] and l<r-1) r--;
                    l++;
                    r--;
                   
                    
                }
                else if(el+v[l]+v[r]<0)
                {
                    l++;
                }
                else{
                    r--;
                }
            }
            
        }
        return totans;
    }
};