class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        
        string temp;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]==' ' or i==s.size())
            {
                if(temp.size()==0)
                {
                    continue;
                }
                
                v.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        
        string ans;
        for(int i=v.size()-1;i>=0;i--)
        {
            ans+=v[i];
            if(i!=0){
            ans.push_back(' ');
            }
        }
        
        return ans;
        
        
    }
};