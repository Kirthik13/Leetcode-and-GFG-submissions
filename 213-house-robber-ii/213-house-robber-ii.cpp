class Solution {
public:
 map<pair<int,int>,int>dp;
    int fn(int idx,vector<int>&v,vector<int>&vis,bool rob)
    {
        if(idx>=v.size() or (idx==v.size()-1 and rob))
        {
            return 0;
        }
        
        if(dp.find({idx,rob})!=dp.end()) return dp[{idx,rob}];
        int f=0,s=0;
        
        if(idx==0){
            f=v[idx]+fn(idx+2,v,vis,1);
        }
        else{
            f=v[idx]+fn(idx+2,v,vis,rob);

        }
        
        s=fn(idx+1,v,vis,rob);
        
       return dp[{idx,rob}]=max(f,s);
   
    }
    int rob(vector<int>& v) {
        int n=v.size();
        vector<int>vis(n);
        bool rob=0;
        return fn(0,v,vis,rob);
    }
};