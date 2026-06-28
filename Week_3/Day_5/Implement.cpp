auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyQueue {
private:
    
    std::stack<int, std::vector<int>> input;
    std::stack<int, std::vector<int>> output;

    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    int pop() {
        shiftStacks();
        int frontElement = output.top();
        output.pop();
        return frontElement;
    }
    
    int peek() {
        shiftStacks();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};