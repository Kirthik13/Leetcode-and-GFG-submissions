class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int st=0,ans=0,zc=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                zc++;
            }
            
            while(zc>k)
            {
                if(v[st]==0) zc--;
                st++;
            }
            
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};