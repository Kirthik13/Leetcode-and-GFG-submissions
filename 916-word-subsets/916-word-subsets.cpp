class Solution {
public:
    vector<int> counter(string s)
    {
        vector<int>count(26);
        
        for(auto &i:s)
        {
            count[i-'a']++;
        }
        return count;
    }
    vector<string> wordSubsets(vector<string>& v1, vector<string>& v2) {
        
        vector<int>count(26),temp(26);
        
        for(auto &i:v2)
        {
            temp=counter(i);
            
            for(int j=0;j<26;j++)
            {
                count[j]=max(count[j],temp[j]);
            }
        }
        
        vector<string>totans;
        
        for(auto &i:v1)
        {
            temp=counter(i);
            int j;
            for(j=0;j<26;j++)
            {
                if(count[j]>temp[j]) break;
            }
            if(j==26) totans.push_back(i);
        }
        
        return totans;
        
        
          // vector<int> count(26), tmp(26);
//         int i;
//         for (string b : B) {
//             tmp = counter(b);
//             for (i = 0; i < 26; ++i)
//                 count[i] = max(count[i], tmp[i]);
//         }
//         vector<string> res;
//         for (string a : A) {
//             tmp = counter(a);
//             for (i = 0; i < 26; ++i)
//                 if (tmp[i] < count[i])
//                     break;
//             if (i == 26) res.push_back(a);
//         }
//         return res;
        
        
    }
};