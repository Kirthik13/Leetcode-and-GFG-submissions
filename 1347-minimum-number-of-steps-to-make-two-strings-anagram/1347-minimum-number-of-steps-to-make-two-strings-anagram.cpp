class Solution {
public:
    int minSteps(string s, string t) {
        // map<char,int>m1;
        // map<char,int>m2;
        
        vector<int>freq(27);
        
        for(auto &i:s) freq[int(i)-'a']++;
        for(auto &i:t)  freq[int(i)-'a']--;
        
        int cnt{};
        // for(auto &i:m1)
        // {
        //     if(m1[i.first]>m2[i.first])
        //     {
        //         cnt+=abs(m1[i.first]-m2[i.first]);
        //     }
        // }
        
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]>0)
            {
                cnt+=freq[i];
            }
        }
        
        return cnt;
        
        
    }
};