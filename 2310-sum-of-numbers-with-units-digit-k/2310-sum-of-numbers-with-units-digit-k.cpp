class Solution {
public:
    int fn(int num,int k,vector<int>&v,int i,int sum, vector<vector<int>>&dp)
    {
        if(i>=v.size())
        {
            if(sum==num) return 0;
            return INT_MAX;
        }
        if(sum==num) return 0;

        if(sum>num) return INT_MAX;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int inc=INT_MAX;
        int notinc=INT_MAX;
        
        if(sum+v[i]<=num)
        {
            inc=fn(num,k,v,i,sum+v[i],dp);
            if(inc!=INT_MAX)
            {
                inc++;
            }
            notinc=fn(num,k,v,i+1,sum,dp);
            return dp[i][sum]=min(inc,notinc);


            
        }
        notinc=fn(num,k,v,i+1,sum,dp);
        
        return notinc;
    }
    int minimumNumbers(int num, int k) {
        if(num==0 ) return 0;
    
        vector<int>v;
        
        for(int i=1;i<=num;i++)
        {
            if(i%10==k)
            {
                v.push_back(i);
            }
        
        }
        int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(num+1,-1));

        int ans=fn(num,k,v,0,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};