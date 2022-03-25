class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& v) {
        int n=v.size();
        sort(begin(v),end(v),[](auto a,auto b)
             {
                 return a[0]-a[1]<b[0]-b[1];
             });
            
        int ans{};
        for(int i=0;i<(v.size()/2);i++)
        {
            ans+=v[i][0]+v[i+(v.size()/2)][1];
        }
        return ans;
    }
};