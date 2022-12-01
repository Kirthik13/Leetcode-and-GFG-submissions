class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int>m;
        m['a']=0;
        m['e']=0;
        m['i']=0;
        m['o']=0;
        m['u']=0;
        m['A']=0;
        m['E']=0;
        m['I']=0;
        m['O']=0;
        m['U']=0;
        int j=s.size()-1;
        int a{},b{};
        for(int i=0;i<(s.size()/2);i++)
        {
            
            if(m.find(s[i])!=m.end()) a++;
            if(m.find(s[j])!=m.end()) b++;
            
            j--;
            
            
        }
        
        return a==b;
        
    }
};