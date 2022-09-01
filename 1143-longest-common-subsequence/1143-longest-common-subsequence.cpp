class Solution {
public:
    int dp[1001][1001];
    int fn(string &s, string &t,int idx1,int idx2,int m,int n) 
    {
        if(idx1>=m or idx2>=n) return 0;
        
        if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];
        
        if(s[idx1]==t[idx2])
        {
            return dp[idx1][idx2]=1+fn(s,t,idx1+1,idx2+1,m,n);
        }
        int call1=fn(s,t,idx1+1,idx2,m,n);
        int call2=fn(s,t,idx1,idx2+1,m,n);
        
        return dp[idx1][idx2]=max(call1,call2);
       
        
    }
    
    void printset(string &s, string &t,int idx1,int idx2,int m,int n,vector<char>&res,int po) 
    {
        if(idx1>=m or idx2>=n)
        {
            for(auto &i:res)
            {
                cout<<i;
            }
            cout<<endl;
            return ;
        }
        
        
        if(s[idx1]==t[idx2])
        {
            // cout<<s[idx1]<<" ";
            if(res.size()>po)
            {
                res[po]=s[idx1];
            }
            dp[idx1][idx2]=1+fn(s,t,idx1+1,idx2+1,m,n);
            printset(s,t,idx1+1,idx2+1,m,n,res,po+1);
            
        }
        else{
            int call1=fn(s,t,idx1+1,idx2,m,n);
            int call2=fn(s,t,idx1,idx2+1,m,n);

            if(max(call1,call2)==call1)
            {
                printset(s,t,idx1+1,idx2,m,n,res,po);
            }
            else{
                printset(s,t,idx1,idx2+1,m,n,res,po);

            }
        }
       
    }
    int longestCommonSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        memset(dp,-1,sizeof(dp));
        
        int g=fn(s,t,0,0,m,n);
        
        vector<char>res(g);
        printset(s,t,0,0,m,n,res,0);
        return g;
    }
};
