class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s1, vector<string>& s2) {
        // for(auto &i:s1)
        // {
        // sort(begin(i),end(i));
        // }
        // for(auto &i:s2){
        // sort(begin(i),end(i));
        // }
        string t1,t2;
        for(auto &i:s1)
        {
            t1+=i;
        }
          for(auto &i:s2)
        {
            t2+=i;
        }
        // cout<<t1<<" "<<t2<<endl;
        return t1==t2;

    }
};