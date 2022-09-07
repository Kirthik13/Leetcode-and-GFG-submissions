class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lt, vector<int>& req) 
    {
        // vector<pair<int,int>>cov;
        vector<int>cov(n+1);
        
        for(auto &i:lt)
        {
            int l=max(0,i[0]-i[1]);
            int r=min(n-1,i[0]+i[1]);
            
            // cout<<l<<" "<<r<<endl;
            
            cov[l]++;
            cov[r+1]--;
            
        }
        
        for(int i=1;i<n;i++)
        {
            cov[i]+=cov[i-1];
        }
        
        // for(auto &i:cov) cout<<i<<" ";
        
        int cnt{};
        for(int i=0;i<req.size();i++)
        {
            if(req[i]<=cov[i]) cnt++;
        }
        
        return cnt;
        
        
    }
};