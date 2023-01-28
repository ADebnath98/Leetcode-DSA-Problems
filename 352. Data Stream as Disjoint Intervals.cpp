class SummaryRanges {
    map<int, int> m;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left  = value;
        int right = value;
        auto next = m.upper_bound(value);
        
        if (next != m.begin()) {
            
            auto prevx = next;
            --prevx;
            
            if (prevx->second >= value) {
                return;
            }
            if (prevx->second == value - 1) {
                left = prevx->first;
            }
        }
        if (next != m.end() && next->first == value + 1) {
            right = next->second;
            m.erase(next);
        }
        m[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        
        for (const auto& p : m) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};