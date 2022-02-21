class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int e1,e2,c1{},c2{},n=v.size();
        for(int i=0;i<n;i++)
        {
            if(e1==v[i])
            {
                c1++;
            }
           else if(e2==v[i])
            {
                c2++;
            }
           else if(c1==0)
            {
                e1=v[i];
                c1++;
            }
            else if(c2==0)
            {
                e2=v[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
       vector<int>ans;
        if(count(begin(v),end(v),e1)>n/3 )
        {
            ans.push_back(e1);
        }
        if(count(begin(v),end(v),e2)>n/3  and e1!=e2)
        {
                    ans.push_back(e2);

        }
        return ans;
    }
};