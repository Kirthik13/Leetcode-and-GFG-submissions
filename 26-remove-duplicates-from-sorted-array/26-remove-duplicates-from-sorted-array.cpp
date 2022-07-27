class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int el=v[0];
        int idx=1;
        for(int i=1;i<v.size();i++)
        {
            if(el!=v[i])
            {
                v[idx]=v[i];
                el=v[i];
                idx++;
            }
        }
        return idx;
    }
};