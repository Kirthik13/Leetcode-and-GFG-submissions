class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0,j=1;
        while(j<v.size())
        {
            if(v[i]!=v[j])
            {
                i++;

                v[i]=v[j];
            }
            j++;
        }
        return i+1;
    }
};