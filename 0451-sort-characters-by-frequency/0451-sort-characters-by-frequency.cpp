class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        multimap<int,char,greater<int>>m2;
        
        for(auto &i:s) m[i]++;
        
        for(auto &i:m) m2.insert({i.second,i.first});

        string res;
        for(auto &i:m2) 
        {
            
            int c=i.first;

            while(c--)
            {
                res+=i.second;
            }
        }
        
        return res;
        
        

        
        
    }
};