class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int curr_max=0;
        int totans{};
        for(int i=0;i<=v.size();i++)
        {
            if(i<v.size() and v[i]==1)
            {
                curr_max++;
            }
            else{
                totans=max(curr_max,totans);
                curr_max=0;
            }
        }
        return totans;
    }
};