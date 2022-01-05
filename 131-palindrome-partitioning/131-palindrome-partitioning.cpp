class Solution {
public:
    vector<vector<string>>ans;
bool ispalin(string &s)
{
    int n=s.size(),i=0;
    int j=n-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;

}
void part(string &s,int j,vector<string>&vs)
{
    if(j>=s.size())
    {
       ans.push_back(vs);
       return ;
    }

    for(int i=j;i<s.size();i++)
    {
       string curr=s.substr(j,i-j+1); //(start idx, length of substring)
            if(ispalin(curr)){
                vs.push_back(curr);
                part(s,i+1,vs);
                vs.pop_back(); //backtracking
            }
    }

}
    vector<vector<string>> partition(string s) {
        vector<string>vs;
    part(s,0,vs);
        return ans;
    }
    
};