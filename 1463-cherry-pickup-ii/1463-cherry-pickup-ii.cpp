class Solution {
public:
    int dy[3]={-1,0,1};
int n,m;
int dp[71][71][71];
int fn(int row,int c1,int c2,vector<vector<int>>&v)
{
    if(row>=n)
    {
        return 0;
    }
    if(c1<0 or c1>=m or c2<0 or c2>=m)
    {
        return INT_MIN;
    }
    if(dp[row][c1][c2]!=-1)
    {
        return dp[row][c1][c2];
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int newrow=row+1;
            int newcol1=c1+dy[i];
            int newcol2=c2+dy[j];

            if(c1==c2)
            {
                maxi=max(maxi,v[row][c1]+fn(newrow,newcol1,newcol2,v));
            }
            else{
                maxi=max(maxi,v[row][c1]+v[row][c2]+fn(newrow,newcol1,newcol2,v));

            }
        }
    }
    return dp[row][c1][c2]=maxi;


}
    int cherryPickup(vector<vector<int>>& v) {
        n=v.size();
    m=v[0].size();
    memset(dp,-1,sizeof(dp));
    return fn(0,0,m-1,v);
    }
};