class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        string hs=to_string(high);
                string ls=to_string(low);
    vector<int>res;
        int n=s.size();
        for(int i=ls.size();i<=hs.size();i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                // if(s[j]-48>hs[0]-48){
                //     continue;
                // }
                string g=s.substr(j,i);
                int ans=stoi(g);
                if(ans>high)
                {
                    break;
                }
                if(ans<=high and ans>=low)
                {
                    // break;
                // }
                res.emplace_back(ans);
                }
            }
        }
        return res;
    }
};