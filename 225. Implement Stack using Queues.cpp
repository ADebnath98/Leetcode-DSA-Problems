class MyStack {

private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {                             // save the last ele of queue
        int flag = q.back();                // i.e. the top() ele of stack
        for(int i=0; i<q.size()-1; i++)     // iterate till 2nd last element
        {
            q.push(q.front());
            q.pop();
        }                                   // now ull have last ele at front and rest same as previous queue
        q.pop();                            // pop the 1st element
        return flag;
    }
    
    int top() {
        return q.back();                    // built-in function
    }
    
    bool empty() {
        return q.empty();                   // built-in function
    }
};