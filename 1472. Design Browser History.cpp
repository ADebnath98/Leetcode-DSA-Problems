class BrowserHistory {
    vector<string> v;
    int p;
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        p = 0;
    }
    
    void visit(string url) {
        int n = v.size();
        for(int _=0; _<n-p-1; _++) v.pop_back();
        v.push_back(url);
        p++;
    }
    
    string back(int steps) {
        p = max(0, p - steps);
        return v[p];
    }
    
    string forward(int steps) {
        p = min((int)v.size() - 1, p + steps);
        return v[p];
    }
};
// leetcode google facebook linkedin

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */