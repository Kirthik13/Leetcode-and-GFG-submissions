class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int c{};
        for(int i=0;i<v[0].size();i++)
        {
            // string s,t;
            for(int j=0;j<v.size()-1;j++)
            {
                // s.push_back(v[j][i]);
                // t.push_back(v[j][i]);
                if(v[j][i]>v[j+1][i])
                {
                    c++;
                    break;
                }
            }
            
            // sort(begin(t),end(t));
            // if(s!=t) c++;
            
        }
        return c;
    }
};