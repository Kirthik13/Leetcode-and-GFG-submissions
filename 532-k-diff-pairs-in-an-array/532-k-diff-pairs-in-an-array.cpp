class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        unordered_map<int,int>m;
        set<pair<int,int>>st;
        int c{};
        for(int i=0;i<v.size();i++)
        {
            int a,b;
            
                a=v[i]-k;
                b=v[i]+k;
            // }
            // else{
            //     a=v[i]-k;
            // }
            if(m[a]>0 )
            {
                if(st.find({a,v[i]})==st.end() and st.find({v[i],a})==st.end() ){
                st.insert({a,v[i]});
                // if(a!=v[i]){
                        st.insert({v[i],a});
                // }
                c++;
                }

            }
     if(m[b]>0 )
            {
                if(st.find({b,v[i]})==st.end() and st.find({v[i],b})==st.end() ){
                st.insert({b,v[i]});
                // if(a!=v[i]){
                        st.insert({v[i],b});
                // }
                c++;
                }

            }
            m[v[i]]++;
        }
        return c;
        
    }
};