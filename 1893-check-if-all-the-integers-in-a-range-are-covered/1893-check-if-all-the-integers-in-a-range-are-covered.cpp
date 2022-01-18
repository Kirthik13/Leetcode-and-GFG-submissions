class Solution {
public:
    bool isCovered(vector<vector<int>>& v, int l, int r) {
          int pre[52]={0};

    for(auto &i:v)
    {
        ++pre[i[0]];
        --pre[i[1]+1];
    }

    for(int i=1;i<52;i++)
    {
        pre[i]+=pre[i-1];
    }
    for(int i=l;i<=r;i++)
    {
        if(!pre[i])
        {
            return 0;
        }
    }   
    return 1;   
    }
};