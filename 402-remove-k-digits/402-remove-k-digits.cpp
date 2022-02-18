class Solution {
public:
    string removeKdigits(string s, int k) {
        string res;
        if(k==s.size()) return "0";
        int keep=s.size()-k;
        for(int i=0;i<s.size();i++)
        {
            while(res.size()>0 and res.back()>s[i] and k>0)
            {
                k--;
                res.pop_back();
            }
            res.push_back(s[i]);
        }
       res.erase(keep, string::npos);
        
        // trim leading zeros
        int i = 0;
        while (i<(int)res.size()-1 && res[i]=='0')  i++;
        res.erase(0, i);
        
        return res=="" ? "0" : res;
    }
};