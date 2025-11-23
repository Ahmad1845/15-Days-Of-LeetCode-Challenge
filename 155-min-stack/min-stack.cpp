class MinStack {
public:
    stack<int> st;      // main stack
    stack<int> minSt;   // stack to track minimums

    MinStack() { }

    void push(int val) {
        st.push(val);

        // If min stack is empty OR new val <= current min
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        // If popping the current min, remove from min stack too
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */