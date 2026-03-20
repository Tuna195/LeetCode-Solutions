class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> st2, st3;
        st3.push(x);
        while(!st.empty()){
            int top = st.top();st.pop();
            st2.push(top);
        }
        while(!st2.empty()){
            int top = st2.top();st2.pop();
            st3.push(top);
        }
        st = st3;
    }
    
    int pop() {
        int front = peek();
        st.pop();
        return front;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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