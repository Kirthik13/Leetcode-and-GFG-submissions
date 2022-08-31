class Solution {
public:
            // map<pair<pair<int,int>,int>,int>dp;
                map<pair<int,int>,int>dp;

 
    int fn(vector<vector<int>>& v,int idx,int n,int c) 
    {
        if(c==2) return 0;
        if(idx>=n)
        {
            if(c==1 or c==2)
            {
                            return 0;
                

            }
            return INT_MIN;
        }
        
        if(dp.find({idx,c})!=dp.end()) return dp[{idx,c}];
        
        
        vector<int>ans={v[idx][1],INT_MAX,INT_MAX};
        
        //Searching the event whose starting time > ending time of previous event selected
        int nextidx=upper_bound(begin(v),end(v),ans)-begin(v);
        
        
        int call1{},call2{};
        
            call1=v[idx][2]+fn(v,nextidx,n,c+1);
        
             call2=fn(v,idx+1,n,c);        
        
        return dp[{idx,c}]=max(call1,call2);
        
    }
    int maxTwoEvents(vector<vector<int>>& v) {
        sort(begin(v),end(v));
        
       int n=v.size();
        return fn(v,0,n,0);
    }
};