class Solution {
public:
    bool isPossible(vector<int>& v) {
        int n=v.size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>m;
        int ans{};
        for(auto &i:v)
        {
            if(!m[i-1].empty())
            {
                int cnt= m[i-1].top();
                m[i-1].pop();
                cnt++;
                m[i].push(cnt);
                
                if(cnt==3)
                {
                    ans--;
                }
            }
            else{
                ans++;
                m[i].push(1);
            }
        }
        return ans==0;
    }
};


