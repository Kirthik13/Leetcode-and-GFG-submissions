class Solution {
public:
    vector<string>fn(string &s1)
    {
                stringstream ss (s1);
    string item;
    char delim='.';
        vector<string>v1;
    while (getline (ss, item, delim)) {
        v1.push_back (item);
    }
        return v1;
    }
    int compareVersion(string s1, string s2) {

        vector<string>v1=fn(s1);
        vector<string>v2=fn(s2);
        
        int maxl=max(s1.size(),s2.size());
        
        for(int i=0;i<maxl;i++)
        {
            int a=i<v1.size()?(stoi(v1[i])):0;
            int b=i<v2.size()?(stoi(v2[i])):0;
            
            if(a<b) return -1;
            if(a>b) return 1;
            
        }
        return 0;

        
    }
};