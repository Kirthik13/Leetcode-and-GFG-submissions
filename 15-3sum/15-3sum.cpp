class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>>tot;
        
        sort(begin(v),end(v));
        
        for(int i=0;i<v.size();i++)
        {
            if(i>0 and v[i-1]==v[i]) continue;
            int l=i+1,r=v.size()-1;
            while(l<r)
            {
                if(v[l]+v[i]+v[r]==0)
                {
                    tot.push_back({v[i],v[l],v[r]});
                    // break;
                    int l1=v[l],r1=v[r];
                    while(l1==v[l] and l<r) l++;
                    while(r1==v[r] and r>i) r--;
                }
                else if(v[l]+v[r]+v[i]>0)
                {
                    r--;
                }
                else{
                    l++;
                }
            }
            
        }
        return tot;
    }
};