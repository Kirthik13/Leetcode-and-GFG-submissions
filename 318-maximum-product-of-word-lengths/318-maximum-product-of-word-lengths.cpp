class Solution {
public:
    bool isok(bitset<26>&s,bitset<26>&t)
    {
        for(int i=0;i<26;i++)
        {
            if(s[i]&t[i])
            {
                return 0;
            }
        }
        return 1;
    }
    int maxProduct(vector<string>& v) {
        
        int n=v.size();
        vector<bitset<26>>st(n);
        int ans{};
        for(int i=0;i<n;i++)
        {
            for(auto &j:v[i])
            {
                st[i][j-'a']=1;
            }
            for(int k=0;k<i;k++)
            {
                if(isok(st[i],st[k]))
                {
                    int m1=v[i].size(),m2=v[k].size();
                    ans=max(ans,(m1*m2));
                }
            }
            
        }
        return ans;
        
        
    }
};