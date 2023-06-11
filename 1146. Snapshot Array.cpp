class SnapshotArray {
public:
    SnapshotArray(int length) {
        m_data.resize(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        m_data[index][m_snap_id] = val;
    }
    
    int snap() {
        return m_snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = m_data[index].upper_bound(snap_id);
        return std::prev(it)->second;
    }
    
private:
    int m_snap_id {0};
    std::vector<std::map<int, int>> m_data;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */