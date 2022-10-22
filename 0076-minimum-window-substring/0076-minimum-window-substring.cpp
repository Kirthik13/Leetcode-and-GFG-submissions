class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m;
        for(auto &i:t)
        {
            m[i]++;
        }
        
        int r=0,l=0,win=t.size();
        int count=win,head{},minlen=INT_MAX;
        
        
        while(r<s.size())
        {
            if(m[s[r]]>0)
            {
                count--;
            }
            m[s[r]]--;
            
            while(count==0)
            {
                if(r-l+1<minlen)
                {
                    head=l;
                    minlen=r-l+1;
                }
                
                if(m.find(s[l])!=m.end() and m[s[l]]>=0) count++;
                m[s[l]]++;
                l++;
            }
            r++;
            
            
        }
       
        return minlen==INT_MAX?"":s.substr(head,minlen);
           
    }
};