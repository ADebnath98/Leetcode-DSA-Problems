class FrontMiddleBackQueue {
public:
    int size=0;
    deque<int> left;
    deque<int> right;
    FrontMiddleBackQueue() {
    }
    void pushFront(int val) {
        if(size%2==0){
            left.push_front(val);
        }
        else{
            int x = left.back();
            left.pop_back();
            left.push_front(val);
            right.push_front(x);
        }
        size++;
    }
    void pushMiddle(int val) {
        if(size%2==0){
            left.push_back(val);
        }
        else{
            int x = left.back();
            left.pop_back();
            left.push_back(val);
            right.push_front(x);
        }
        size++;
    }
    
    void pushBack(int val) {
        if(size%2==0){
            if(size!=0){
                int x = right.front();
                left.push_back(x);
                right.pop_front();
                right.push_back(val);
            }
            else{
                left.push_back(val);
            }
        }
        else{
            right.push_back(val);
        }
        size++;
    }
    
    int popFront() {
        if(size==0) return -1;
        if(size%2==0){
            int x = left.front();
            left.pop_front();
            int y = right.front();
            right.pop_front();
            left.push_back(y);
            size--;
            return x;
        }
        else{
            int x =left.front();
            left.pop_front();
            size--;
            return x;
        }
    }
    
    int popMiddle() {
        if(size==0) return -1;
        if(size%2==0){
            int x = left.back();
            int y = right.front();
            right.pop_front();
            left.pop_back();
            left.push_back(y);
            size--;
            return x;
        }
        else{
            int x =left.back();
            left.pop_back();
            size--;
            return x;
        }
    }
    
    int popBack() {
        if(size==0) return -1;
        if(size%2==0){
            int x = right.back();
            right.pop_back();
            size--;
            return x;
        }
        else{
            if(size==1) {
                int x = left.back();
                left.pop_back();
                size--;
                return x;
            }
            else{
                int x = right.back();
                right.pop_back();
                int y =left.back();
                left.pop_back();
                right.push_front(y);
                size--;
                return x;
            }
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */