class MyQueue {
public:
     stack<int>s;
    MyQueue() { }   
    void push(int x) {
        if(s.empty()){
            s.push(x);
            return;
        }
        int ans=s.top();
        s.pop();
        push(x);
        s.push(ans);
    }
    
    int pop() {
        int ans=s.top();
        s.pop();
        return ans;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        if(s.empty())return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */