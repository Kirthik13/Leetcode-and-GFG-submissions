class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        if(v.size()==0) return {};
        vector<string>tot;
        int pre=0;
        int curr=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]==v[i]-1)
            {
                curr=i;
                continue;
            }
            else{
                string s1=to_string(v[pre]);
                string s2=to_string(v[curr]);
                 string ans=s1;
                if(s1!=s2){
                 ans=s1+"->"+s2;
                }
                
                tot.push_back(ans);
                pre=i;
                curr=i;
            }
            
        }
        string s1=to_string(v[pre]);
                string s2=to_string(v[curr]);
                 string ans=s1;
                if(s1!=s2){
                 ans=s1+"->"+s2;
                }
                
                tot.push_back(ans);
        return tot;
    }
};