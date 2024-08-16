#include<bits/stdc++.h>
using namespace std;

class MinStack{
    public:
    stack<int> stk;
    int min_element;
    int size;
    MinStack(int max_size) {
        size = max_size;
    }
    bool is_empty() {
        return stk.empty();
    }
    bool is_full() {
        return stk.size() == size;
    }
    void push(int x) {
        // if size < max_size
        if(stk.empty()) {
            stk.push(x);
            min_element = x;
        } else {
            if(x < min_element) {
                stk.push(2 * x - min_element);
                min_element = x;
            } else {
                stk.push(x);
            }
        }
    }
    void pop() {
        // if is_empty return
        if(stk.top() >= min_element) {
            stk.pop();
        } else {
            min_element = 2 * min_element - stk.top();
            stk.pop();
        }
    }
    int get_min() { 
        return min_element;
    }
};

int main() {
    int n;
    cin >> n;
    MinStack my_stack(n);
    while(n--) {
        int x;
        cin >> x;
        my_stack.push(x);
    }
    while(!my_stack.is_empty()) {
        cout << "current top of stack is " << my_stack.stk.top() << " and minimum is " << my_stack.min_element << '\n';
        my_stack.pop();
    }
}