/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int it=0;
    vector<int>v;
    void fn(vector<NestedInteger>v2)
    {
        for(auto i:v2)
        {
            if(i.isInteger())
            {
                v.push_back(i.getInteger());
            }
            else{
                

                fn(i.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto &i:nestedList)
        {
            if(!i.isInteger())
            {
                vector<NestedInteger> v2=i.getList();
                fn(v2);
//                 for(auto &j:v2)
//                 {
//                     if(j.isInteger()){
//                     int g=j.getInteger();
//                     v.push_back(g);
//                     }
//                     else{
                        
//                         fn(j.getList());
//                     }

//                 }
                    
            }
            else{
                    int g=i.getInteger();
                    v.push_back(g); 
            }
        }
    }
    
    int next() {
        return v[it++];
    }
    
    bool hasNext() {
        if(it<v.size()) return 1;
        return 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */