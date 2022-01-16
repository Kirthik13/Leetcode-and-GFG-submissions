class Solution {
public:
    int fn(int &idx,int &n,vector<int>&v)
{
    int c1=1,c2=1;
    int i=idx-1;
    int j=idx+1;

    while(i>=0 or j<n)
    {
       if(j<n)
        {
            if(v[j]==1)
            {
                break;
            }
        }
        if(i>=0)
        {
            if(v[i]==1)
            {
                break;
            }
        }
        c1++;

        i>=0?--i:i;
        j<n?++j:j;

    }

    return c1;
}
    int maxDistToClosest(vector<int>&v) {
        int n=v.size(),ans=INT_MIN;
int i=0;
while(i<n)
{
    if(v[i]==0)
    {
        // continue;
    ans=max(ans,fn(i,n,v));
    }
    i++;
}
        return ans;
    }
};