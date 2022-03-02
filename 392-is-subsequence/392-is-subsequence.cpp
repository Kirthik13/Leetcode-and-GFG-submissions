class Solution {
public:
    bool fn(string s,string t,int idx1,int idx2)
    {
        if(idx1==s.size())
        {
            return 1;
        }
        if(idx2==t.size())
        {
            if(idx1==s.size()) return 1;
            return 0;
        }
                bool g=0;

        if(s[idx1]==t[idx2])
        {
            return fn(s,t,idx1+1,idx2+1);
        }
        else{
        g=fn(s,t,idx1,idx2+1);
        }
        return g;
    }
    bool isSubsequence(string s, string t) {
    if(s.size()==0)
    {
        // if(t.size()==0) return 1;
        return 1;
    }
    if(t.size()==0)
    {
        if(s.size()==0) return 1;
        return 0;
    }
       return fn(s,t,0,0);
    }
};