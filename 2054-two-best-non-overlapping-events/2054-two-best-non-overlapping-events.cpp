// class Solution {
// public:
//             // map<pair<pair<int,int>,int>,int>dp;
//                 // map<pair<int,int>,int>dp;

 
//     int fn(vector<vector<int>>& v,int idx,int n,int c, vector<vector<int>>&dp) 
//     {
//         if(c==2) return 0;
//         if(idx>=n)
//         {
           
//                             return 0;
                

            
//         }
        
//         if(dp[idx][c]!=-1) return dp[idx][c];
        
        
//         vector<int>ans={v[idx][1],INT_MAX,INT_MAX};
        
//         int nextidx=upper_bound(begin(v),end(v),ans)-begin(v);
        
        
//         int call1{},call2{};
        
//             call1=v[idx][2]+fn(v,nextidx,n,c+1,dp);
        
//              call2=fn(v,idx+1,n,c,dp);        
        
//         return dp[idx][c]=max(call1,call2);
        
//     }
//     int maxTwoEvents(vector<vector<int>>& v) {
//         sort(begin(v),end(v),[](auto a,auto b)
//              {
//                  return a[0]<b[0];
//              });
        
//        int n=v.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return fn(v,0,n,0,dp);
//     }
// };


class Solution {
public:
    
    //Main Function
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        //Sorting because since we need to find an event that has starting time > ending time 
        //of previous event selected, so applying binary search would help there.
        sort(events.begin(),events.end());
        
        return solve(events,0,0,dp);
    }
    
    //Helper function
    int solve(vector<vector<int>>&nums,int idx,int k,vector<vector<int>>&dp)
    {
        // Base case
        if(k==2)
        {
            return 0;
        }
        if(idx>=nums.size())
        {
            return 0;
        }
        
        // Memoization check
        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }
        
        //Basically ending times of the events
        vector<int>ans={nums[idx][1],INT_MAX,INT_MAX};
        
        //Searching the event whose starting time > ending time of previous event selected
        int nextindex=upper_bound(begin(nums),end(nums),ans)-begin(nums);
        
        //Pick event
        int include=nums[idx][2]+solve(nums,nextindex,k+1,dp);
        
        //Don't Pick event
        int exclude=solve(nums,idx+1,k,dp);
        
        return dp[idx][k]=max(include,exclude); //Max of(Pick, Not Pick)
    }
};