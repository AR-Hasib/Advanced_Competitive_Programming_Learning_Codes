/* https://leetcode.com/problems/min-stack/description/ */

class MinStack {
public:
    stack<int>st, mono; 
    MinStack() {    
    }
    
    void push(int val) {
        st.push(val);
        if(mono.empty()) mono.push(val);
        else mono.push(min(val, mono.top()));
    }
    
    void pop() {
        st.pop();
        mono.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mono.top();
    }
};