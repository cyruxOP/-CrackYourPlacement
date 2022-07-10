class MinStack {
    stack<long long>st;
    long long min;
public:
    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min=val;
        }
        else{
            if(val<min)
            {
                st.push(val*1LL*2- min);
                min=val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el<min)
         min= 1LL*2*min -el;
    }
    
    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        if(el<min)
            return min;
        return el;
    }
    
    int getMin() {
        return min;
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