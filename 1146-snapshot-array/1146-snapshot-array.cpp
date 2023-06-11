class SnapshotArray {
public:
    int snappy{};
   map<int,map<int,int>>m;
    SnapshotArray(int length) {
    }
    
    void set(int idx, int val) {
        m[idx][snappy]=val;
    }
    
    int snap() {
       
        return snappy++;
    }
    
    int get(int idx, int snap_idx) {
       
     auto it = m[idx].upper_bound(snap_idx);
  return it == begin(m[idx]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */