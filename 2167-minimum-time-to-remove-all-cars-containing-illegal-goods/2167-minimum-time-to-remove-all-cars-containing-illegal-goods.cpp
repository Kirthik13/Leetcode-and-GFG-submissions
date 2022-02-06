class Solution {
public:
  
    int minimumTime(string s) {
        int n=s.size(),res=INT_MAX;
        vector<int>l(n,0);
        vector<int>r(n,0);
        if(s[0]=='1') l[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1'){
            l[i]=min(l[i-1]+2,i+1);
            }
            else{
                l[i]=l[i-1];
            }
        }
        if(s[n-1]=='1') r[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='1'){
            r[i]=min(r[i+1]+2,n-i);
            }
            else{
                r[i]=r[i+1];
            }
        }
        res=min(r[0],l[n-1]);
        for(int i=0;i<n-1;i++)
        {
            res=min(res,l[i]+r[i+1]);
        }
        return res;
       
    }
};