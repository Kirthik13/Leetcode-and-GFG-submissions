class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int ans{};
        // for(auto &i:v)
        // {
        //     auto idx=upper_bound(rbegin(i),rend(i),-1)-i.rbegin();
        //     // cout<<idx<<endl;
        //     ans+=(idx);
        // }
        
        int r=0,m=v.size(),n=v[0].size(),c=n-1;
        while(r<m)
        {
            while(c>=0 and v[r][c]<0) c--;
            ans+=(n-c-1);
            r++;
        }
        return ans;
    }
};