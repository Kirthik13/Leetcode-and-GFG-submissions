class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int f=v[0],s=v[0];
        do
        {
            s=v[s];
            f=v[v[f]];
        }while(s!=f);

        f=v[0];
        while(s!=f)
        {
            s=v[s];
            f=v[f];
        }
        return s;
    }
};