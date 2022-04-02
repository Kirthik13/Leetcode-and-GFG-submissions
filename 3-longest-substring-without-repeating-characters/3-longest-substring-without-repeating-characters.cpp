class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        map<char,int>m;
        int ans=INT_MIN,st{};
        for(int i=0;i<s.size();i++)
        {
            if(m.count(s[i])>0)
            {
                st=max(st,m[s[i]]+1);
            }
            m[s[i]]=i;
            
            ans=max(ans,i-st+1);
        }
        return ans;
            
    }
};