class SmallestInfiniteSet {
public:
    int smallest;
    set<int> s;
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
         if(s.size()){
            int res=*s.begin(); s.erase(res);
            return res;
        }else{
            smallest++;
            return smallest-1;
        }
    }
    
    void addBack(int num) {
         if(smallest>num) s.insert(num);
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */