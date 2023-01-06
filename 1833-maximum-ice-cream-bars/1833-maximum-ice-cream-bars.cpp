class Solution {
public:
    int maxIceCream(vector<int>& v, int k) {
        int n=v.size();
        sort(begin(v),end(v));
        int c{};
        // priority_queue<int,vector<int>,greater<int>>pq;
        // for(auto &i:v) pq.push(i);
//         while(!pq.empty() and k>0)
//         {
//             auto val=pq.top();
//             if(val<=k)
//             {
//                 k-=val;
//                 pq.pop();

//             }
//             else{
//                 break;
//             }
//         }
        // return n-pq.size();
        for(auto &i:v)
        {
             auto val=i;
            if(val<=k)
            {
                k-=val;
                c++;
            }
            else{
                break;
            }
        }
        return c;
    }
};