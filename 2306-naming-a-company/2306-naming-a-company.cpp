#define ll long long
class Solution {
public:
    long long distinctNames(vector<string>& v) {
        ll ans{};
        map<char,unordered_set<string>>m;
        for(auto &i:v)
        {
            m[i[0]].insert(i.substr(1));
        }
    
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                ll p1{},p2{};
                char s=i+'a',t=j+'a';
                
                for(auto &part1:m[s])
                {
                    if(m[t].find(part1)==m[t].end()) p1++;
                }
                for(auto &part2:m[t])
                {
                    if(m[s].find(part2)==m[s].end()) p2++;
                }
                
                ans+=(p1*p2);
            }
        }
        return ans*2;
    }
};