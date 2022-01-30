class Solution {
public:
    void rotate(vector<int>& v, int k) {
        if(k==0)
        {
            return ;
        }
        int n=v.size();
      k=k%n;   
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[(i+k)%n]=v[i];
        }
        for(int i=0;i<n;i++)
        {
            v[i]=ans[i];
        }
    }
};