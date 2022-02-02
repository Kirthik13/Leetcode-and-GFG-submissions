class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums2.size(),-1);
        stack<int>s;
        map<int,int>m;
        for(auto &i:nums1)
        {
            m[i]=0;
        }
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                m[nums2[i]]=-1;
                s.push(nums2[i]);
                continue;
            }
            else if(!s.empty())
            {
                int c=nums2[i];
                while(!s.empty() and s.top()<=c)
                {
                    s.pop();
                }
                if(!s.empty()){
                    ans[i]=s.top();
                }
                if(m.find(c)!=m.end())
                {
                    if(!s.empty()){
                    m[c]=s.top();
                        }
                    else{
                        m[c]=-1;
                    }
                }
                
            }
            s.push(nums2[i]);
            
        }
        // sort(begin(nums1),end(nums1));
        vector<int>res(nums1.size(),-1);
        // int j=0;
        for(int i=0;i<res.size();i++)
        {
           res[i]=m[nums1[i]];
        }
        return res;
    }
};