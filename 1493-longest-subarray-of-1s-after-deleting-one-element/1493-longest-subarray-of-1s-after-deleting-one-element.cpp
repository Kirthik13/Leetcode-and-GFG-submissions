class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        int ans=0,cnt{},prevcnt{};
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==1 )
            {
                cnt++;               
            }
            else{
                ans=max(ans,cnt+prevcnt);
                prevcnt=cnt;
                cnt=0;                
            }
        }
        ans=max(ans,cnt+prevcnt);
        return ans==n?ans-1:ans;
    }
};