class MinStack {
public:
    vector<int> stack;
    vector<int> min_stack;
    int size;
    MinStack() {
        stack = {};
        min_stack = {};
        size = 0;
    }
    
    void push(int val) {
        int min = val;
        if(size > 0)
            min = val < min_stack[size-1] ? val : min_stack[size-1];
        stack.push_back(val);
        min_stack.push_back(min);
        size++;
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
        size--;
    }
    
    int top() {
        return stack[size-1];
    }
    
    int getMin() {
        return min_stack[size-1];
    }
};
