class Solution {
public:
    int fn(int &idx, int &n, vector<int> &v, unordered_map<int, vector<int>> &m)
{
    int bf = INT_MAX, af = INT_MAX;
  
    for(auto i:m[1])
    {
        if(i>idx)
        {
            af=i;
            break;
        }
        bf=i;
    }
    // deb2(bf, af);
    if(bf==INT_MAX )
    {
        return af-idx;
    }
    else if(af==INT_MAX)
    {
        return idx-bf;

    }
    return min(af-idx, idx-bf);
    
}
    int maxDistToClosest(vector<int>& v) {
        int n = v.size(), ans = INT_MIN;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            m[v[i]].push_back(i);
        }
    }
  
    int i = 0;
    while (i < n)
    {
        if (v[i] == 0)
        {
            
            ans = max(ans, fn(i, n, v, m));
        }
        i++;
    }
        return ans;
    }
};