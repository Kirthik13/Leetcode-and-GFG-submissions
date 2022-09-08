class Solution {
public:
    int removeElement(vector<int>&v, int val) {
        int idx{};
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==val)
            {
                idx=min(idx,i);
            }
            else{
                
                swap(v[i],v[idx]);
                idx++;
            }
        }
       
        return idx;
    }
};