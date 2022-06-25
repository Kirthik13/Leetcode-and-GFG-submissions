class Solution {
public:
    bool checkPossibility(vector<int>& v) {
      int cnt{};
        int mn=INT_MIN;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]<=v[i+1])
            {
                mn=v[i];
            }
            else{
                if(v[i+1]<mn)
                {
                    v[i+1]=v[i];
                }
                else{
                    v[i]=v[i+1];
                }
                cnt++;
            }
        }
        return cnt<=1;
    }
};