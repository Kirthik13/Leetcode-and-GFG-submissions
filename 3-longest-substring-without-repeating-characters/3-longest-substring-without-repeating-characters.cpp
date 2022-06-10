class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans{},st{};
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                st=max(st,m[s[i]]+1);
            }
            m[s[i]]=i;
                ans=max(ans,i-st+1);
            
           
        }
        // ans=max((int)m.size(),ans);
        return ans;
            
    }
};