class Solution {
public:
    int ans=0;
    void fn(vector<vector<int>>& v,int idx,int n,int curr, vector<int>&cnt)
    {
        if(idx==v.size())
        {
            for(auto &i:cnt)
            {
                if(i!=0)
                {
                    return;
                }
            }
            ans=max(ans,curr);
            return;
        }
        
        cnt[v[idx][0]]--;
        cnt[v[idx][1]]++;
        fn(v,idx+1,n,curr+1,cnt);

        
        cnt[v[idx][0]]++;
        cnt[v[idx][1]]--;            
        
        fn(v,idx+1,n,curr,cnt);
    }
    
    int maximumRequests(int n, vector<vector<int>>& v) {
        int curr{};
        vector<int>cnt(n);
        fn(v,0,n,curr,cnt);
        return ans;
    }
};