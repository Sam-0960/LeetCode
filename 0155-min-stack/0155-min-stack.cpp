class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() { min = INT_MAX; }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            min = value;
            return;
        }
        if (min <= value)
            st.push(value);
        else {
            st.push(2LL * value - min);
            min = value;
        }
    }

    void pop() {
        if (st.empty()) return;
        long long n = st.top();
        if (n < min) {
            min = 2LL*min - n; 
        }
        st.pop();
    }

    int top() {
        if (st.empty())
            return -1;
        long long n = st.top();
        if(n>=min) return(int) n;
        else return(int) min;
    }

    int getMin() { 
        if(st.empty()) return -1;
        return (int)min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */