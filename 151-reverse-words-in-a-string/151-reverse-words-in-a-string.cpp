class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        stringstream ss(s);
        string tem;
        while(ss>>tem)
        {
            v.push_back(tem);
        }
        string ans;
        for(int i=v.size()-1;i>=0;i--)
        {
            ans+=v[i];
            if(i!=0)
            {
                ans.push_back(' ');
            }
        }
        return ans;
    }
};