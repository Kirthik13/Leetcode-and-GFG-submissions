class Solution {
public:
    vector<vector<string>>tot;
    bool ispalin(string &s)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    void fn(string s,int idx,int n,vector<string>&v)
    {
        if(idx>=n)
        {
            tot.push_back(v);
            return ;
        }
        
        for(int i=idx;i<n;i++)
        {
            string tem=s.substr(idx,i-idx+1);
            if(ispalin(tem))
            {
                v.push_back(tem);
                fn(s,i+1,n,v);
                if(v.size()>0) v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        int n=s.size();
        fn(s,0,n,v);
        return tot;
    }
};