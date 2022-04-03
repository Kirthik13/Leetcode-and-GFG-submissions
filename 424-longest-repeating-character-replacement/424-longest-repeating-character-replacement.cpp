class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int ans=INT_MIN,st{},freqc{};
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            freqc=max(freqc,m[s[i]]);
            
            int letterstochange=(i-st+1)-freqc;
            
            if(letterstochange>k)
            {
                m[s[st]]--;
                st++;
            }
            ans=max(ans,i-st+1);
            
        }
        return ans;
    }
};