class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        myStack.push_back(x);
        if (minEleStack.empty() == true || x <= minEleStack[minEleStack.size() - 1]) {
            minEleStack.push_back(x);
        }
    }

    void pop() {
        int popEle = myStack[myStack.size() - 1];
        myStack.pop_back();

        if (popEle == minEleStack[minEleStack.size() - 1]) {
            minEleStack.pop_back();
        }
    }

    int top() {
        return myStack[myStack.size() - 1];
    }

    int getMin() {
        return minEleStack[minEleStack.size() - 1];
    }

private:
    vector<int> myStack;
    vector<int> minEleStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */