class Solution {
public:
    bool isCircularSentence(string s) {
        stringstream ss(s);
        string t;
        vector<string>v;
        while(ss>>t)
        {
            v.push_back(t);
        }
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1].back()!=v[i].front()) return 0;
        }
        
        
        
        return v[0].front()==v.back().back();
    }
};