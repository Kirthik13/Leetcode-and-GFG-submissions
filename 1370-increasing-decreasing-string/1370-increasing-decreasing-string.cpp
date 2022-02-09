class Solution {
public:
    string sortString(string s) {
        if(s.size()==1)
        {
            return s;
        }
        string t;
    int n=s.size();
       
        vector<int>m(26,0);
        for(auto &i:s)
        {
            m[i-'a']++;
        }
                // vector<int>m2=m;

       
        int i=0;
        int f=0;
        while(t.size()<s.size())
        {
            int sum=accumulate(m.begin(),m.end(),0);
            if(sum==0)
            {
                break;
            }
            if(m[i]>0)
            {
                m[i]--;
                char ch=char(i)+'a';
                t+=ch;
                
            }
            
            if(!f){
            i++;
            if(i==26)
            {
                i=25;
                f=1;
                // m=m2;
            }
            }
            else if(f)
            {
                i--;
            if(i==-1)
            {
                i=0;
                f=0;
                // m=m2;
            }
            }
            
            
        }
        return t;
            
    }
};