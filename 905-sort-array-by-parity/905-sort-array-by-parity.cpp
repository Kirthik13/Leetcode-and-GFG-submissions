class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int n=v.size();
//         int odd=n-1,even=0;
//         while(even<odd )
//         {
//             if(v[even]%2==0)
//             {
//                 even++;
//             }
//             else{
//                 swap(v[even],v[odd]);
//                 odd--;
               
//             }
//         }
        int i=0,j=0;
        while(j<n)
        {
            if(v[j]%2==0)
            {
                swap(v[i],v[j]);
                i++;
            }
            j++;
        }
        return v;
        
    }
};