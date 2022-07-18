class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& v, vector<vector<int>>& q) {
        vector<int>res;
        for(auto &i:q)
        {
            int kth=i[0],trim=i[1];
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int j=0;j<v.size();j++)
            {
                string s=v[j];
                int n=s.size();
                if(n-trim>0){
                    s=s.substr(n-trim);
                }
                // cout<<"s : "<<s<<endl;
                pq.push({s,j});
                // cout<<"s : "<<s<<endl;
                // if(pq.size()==kth) pq.pop();
                // cout<<"pt : "<<pq.top().first<<endl;
            }
            // cout<<pq.top().first<<endl;
            int el=0;
            while(kth-- and pq.size())
            {
                el=pq.top().second;
                // cout<<"el : "<<pq.top().first<<endl;
                pq.pop();
            }
            res.push_back(el);
            
            
        }
        return res;
    }
};