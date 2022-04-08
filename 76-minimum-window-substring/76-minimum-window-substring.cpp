class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1;
        
        for(auto &i:t)
        {
            m1[i]++;
        }
        
        int count=t.size();
        
        int l{},r{},minlen=INT_MAX,head{};
        string ans;
        
        while(r<s.size())
        {
            if(m1.count(s[r]) and m1[s[r]]>0)
            {
                count--;
            }
            m1[s[r]]--;

            r++;
            while(count==0 )
            {
                if(minlen>r-l)
                {
                    head=l;
                    minlen=r-l;
                }
                m1[s[l]]++;

                if(m1[s[l]]>0) count++;

                l++;
            }
            
            
        }
        return minlen==INT_MAX?"":s.substr(head,minlen);
        
    }
};