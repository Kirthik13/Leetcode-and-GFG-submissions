class Solution {
public:
    int bagOfTokensScore(vector<int>&v, int power) {
        sort(begin(v),end(v));
        
        int l=0,r=v.size()-1,ans{},curr{};
 if(v.size()==0 || power<v[0]) return 0;        
        
        while(l<=r)
        {
            if(power>=v[l])
            {
                power-=v[l++];
                curr++;
                ans=max(ans,curr);
            }
            else{
                power+=v[r--];
                curr--;
                // ans=max(ans,curr);
            }
        }
        
        return ans;
    }
};