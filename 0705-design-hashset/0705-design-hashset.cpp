class MyHashSet {
public:
    vector<list<int>>v;
    MyHashSet() {
        v.resize(1500);
    }
    
    
    int gethashidx(int key)
    {
        return key%1500;
    }
    
    void add(int key) {
        int hashidx=gethashidx(key);
        v[hashidx].push_back(key);
    }
    
    void remove(int key) {
        int hashidx=gethashidx(key);
        auto it=find(v[hashidx].begin(),v[hashidx].end(),key);
        if(it==v[hashidx].end()) return ;
        v[hashidx].remove(key);
    }
    
    bool contains(int key) {
         int hashidx=gethashidx(key);
        auto it=find(v[hashidx].begin(),v[hashidx].end(),key);
        if(it==v[hashidx].end()) return 0;
        return 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */