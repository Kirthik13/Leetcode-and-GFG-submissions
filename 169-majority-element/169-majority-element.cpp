class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n=v.size();
        int c=1,ele=v[0];
        for(int i=1;i<n;i++)
        {
            if(ele!=v[i])
            {
                c--;
                if(c==0)
                {
                    ele=v[i];
                    c++;
                }
            }
            else{
                c++;
            }
        }
        return ele;
    }
};