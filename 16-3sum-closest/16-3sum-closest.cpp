class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(begin(v),end(v));
        int ans=1001;
        for(int i=0;i<v.size();i++)
        {
            
            int l=i+1,r=v.size()-1;
            while(l<r)
            {
                int s=v[i]+v[l]+v[r];
                if(s==target)
                {
                    return s;
                }
                else if(s<target)
                {
                    if(abs(target-s)<abs(target-ans))
                    {
                        ans=s;
                    }
                    l++;
                }
                else if(s>target)
                {
                    if(abs(target-s)<abs(target-ans))
                    {
                        ans=s;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};