class Solution {
public:
    int pivotIndex(vector<int>& v) {
          int n=v.size();
    vector<int>lsum(n,0);
    vector<int>rsum(n,0);
    lsum[0]=v[0];
    rsum[n-1]=v.back();

    for(int i=1;i<n;i++)
    {
        int c=v[i]+lsum[i-1];
        lsum[i]=c;
    }
    for(int i=n-2;i>=0;i--)
    {
        int c=v[i]+rsum[i+1];
        rsum[i]=c;
    }
 
    for(int i=0;i<lsum.size();i++)
    {
        if(lsum[i]==rsum[i])
        {
            return i;
            // break;
        }
    }
        return -1;
    }
};