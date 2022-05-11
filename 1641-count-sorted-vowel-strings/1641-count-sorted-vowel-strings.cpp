class Solution {
public:
    vector<char>let={'a','e','i','o','u'};
    int cnt{};
    void fn(int n,string &s,unordered_map<char,int>&m)
    {
        if(s.size()==n)
        {
            cnt++;
                        // cout<<"s : "<<s<<endl;

            return;
        }
        int idx{};
        if(s.size()>0){
        char ch=s.back();
        idx=m[ch];
        }
        for(int j=idx;j<let.size();j++)
        {
            s.push_back(let[j]);
            fn(n,s,m);
            if(s.size()>0){
            s.pop_back();
            }
            
        }
    }
    int countVowelStrings(int n) {
        unordered_map<char,int>m;
      
        m['a']=0;
        m['e']=1;
        m['i']=2;
        m['o']=3;
        m['u']=4;
        string s;
        fn(n,s,m);
        return cnt;
        
    }
};