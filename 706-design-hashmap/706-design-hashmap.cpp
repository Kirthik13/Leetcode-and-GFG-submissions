class MyHashMap {
public:
    vector<list<pair<int,int>>>v;
    int hashidx=1507;
    MyHashMap() {
        v.resize(1507);
    }
    
    void put(int key, int value) {
        auto &list=v[key%hashidx];
        for(auto &i:list)
        {
            if(i.first==key)
            {
                i.second=value;
                return;
            }
        }
        list.push_back({key,value});
    }
    
    int get(int key) {
        auto &list=v[key%hashidx];
        for(auto &i:list)
        {
            if(i.first==key)
            {
                return i.second;
                
            }
        }
        return -1;
       
    }
    
    void remove(int key) {
        auto &list=v[key%hashidx];
         list.remove_if([key](auto n) { return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */