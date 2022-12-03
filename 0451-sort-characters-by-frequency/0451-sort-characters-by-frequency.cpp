class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        // multimap<int,char,greater<int>>m2;
        priority_queue<pair<int,char>>m2;
        
        for(auto &i:s) m[i]++;
        
        for(auto &i:m) m2.push({i.second,i.first});

        string res;
        while(!m2.empty())
        {
            auto i=m2.top();
            int c=i.first;

            // while(c--)
            // {
            //     res+=i.second;
            // }
            res.append(c,i.second);
            
            m2.pop();
        }
        
        return res;
        
        

        
        
    }
};