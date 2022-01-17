class Solution {
public:
    bool wordPattern(string pat, string s) {
        stringstream ss(s);
        vector<int>v(26,0);
        string sam;
        unordered_map<string,int>m;
        int cnt{};
        int i{};
        while(ss>>sam)
        {
            if(i>=pat.size() or m[sam]!=v[pat[i]-'a']) return 0;
                
            m[sam]=i+1;
            v[pat[i]-'a']=i+1;
            
            i++;
        }
        
        if(i==pat.size())
        {
            return 1;
        }
        return 0;
    }
};