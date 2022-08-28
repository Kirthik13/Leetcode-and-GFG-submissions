class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        
        int ans{},k1{},l{};
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                k1++;
            }
            
            if(k1>k)
            {
                while(l<=i)
                {
                    if(v[l]==0)
                    {
                        k1--;
                        l++;
                        break;
                    }
                    l++;
                }
            }
            ans=max(ans,i-l+1);
        }
       return ans;
        
    }
};