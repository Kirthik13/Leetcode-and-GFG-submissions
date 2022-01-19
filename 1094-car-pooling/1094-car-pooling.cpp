class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int cap) {
        int ans=INT_MIN;
        for(auto &i:v)
        {
            ans=max(ans,i[2]);
        }
        vector<int>pre(ans+1,0);
        
        for(int i=0;i<v.size();i++)
        {
            pre[v[i][1]]+=v[i][0];
                pre[v[i][2]]-=v[i][0];

        }
        int curr{};
        for(int i=0;i<pre.size();i++)
        {
            if(curr+pre[i]>cap)
            {
                return 0;
            }
            curr+=pre[i];
        }
        return 1;
    }
};