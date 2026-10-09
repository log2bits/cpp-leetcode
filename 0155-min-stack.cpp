class MinStack {
public:
    void push(int value) {
        data_stack.push(value);
        if (min_stack.empty() || value <= min_stack.top()) min_stack.push(value);
    }

    void pop() {
        if (top() == getMin()) min_stack.pop();
        data_stack.pop();
    }

    int top() const { return data_stack.top(); }

    int getMin() const { return min_stack.top(); }

private:
    std::stack<int> data_stack;
    std::stack<int> min_stack;
};
