class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int k2{},st{},ans{};
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                k2++;
            }
            
            while(k2>k)
            {
                if(v[st]==0)
                {
                    
                    k2--;
                    st++;
                    break;
                }
                st++;
                
                
            }
            ans=max(ans,i-st+1);
        }
            
        return ans;
    }
};