class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int k2{},l{},ans{};
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                k2++;
            }
            
            if(k2>k)
            {
                while(l<v.size())
                {
                    if(v[l]==0)
                    {
                        k2--;
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