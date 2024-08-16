#include <iostream>
#include <stack>
#include <limits>

using namespace std;

/**
 * @class MinStack
 * @brief A stack that supports push, pop, and retrieving the minimum element in constant time.
 */
class MinStack {
public:
    stack<int> stk;
    int minElement;
    int maxSize;

    /**
     * @brief Constructor for MinStack.
     * @param max_size The maximum size of the stack.
     */
    MinStack(int max_size) {
        maxSize = max_size;
        minElement = numeric_limits<int>::max();
    }

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, otherwise false.
     */
    bool empty() const {
        return stk.empty();
    }

    /**
     * @brief Checks if the stack is full.
     * @return True if the stack has reached its maximum size, otherwise false.
     */
    bool isFull() const {
        return stk.size() == maxSize;
    }

    /**
     * @brief Pushes an element onto the stack.
     * @param x The element to be pushed.
     */
    void push(int x) {
        if (isFull()) {
            cout << "Stack is full. Cannot push element " << x << endl;
            return;
        }

        if (stk.empty()) {
            stk.push(x);
            minElement = x;
        } else {
            if (x < minElement) {
                stk.push(2 * x - minElement);
                minElement = x;
            } else {
                stk.push(x);
            }
        }
    }

    /**
     * @brief Removes the top element from the stack and updates the minimum if necessay.
     */
    void pop() {
        if (stk.empty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        }

        int top = stk.top();
        if (top < minElement) {
            minElement = 2 * minElement - top;
        }
        stk.pop();
    }

    /**
     * @brief Retrieves the minimum element in the stack.
     * @return The minimum element in the stack.
     */
    int getMin() const {
        if (stk.empty()) {
            cout << "Stack is empty. No minimum element." << endl;
            return numeric_limits<int>::max();
        }
        return minElement;
    }

    /**
     * @brief Retrieves the top element of the stack.
     * @return The top element of the stack.
     */
    int top() const {
        if (stk.empty()) {
            cout << "Stack is empty. No top element." << endl;
            return numeric_limits<int>::max();
        }

        int top = stk.top();
        if(top < minElement) {
            return minElement;
        } else {
            return top;
        }
    }

    /**
     * @brief Returns the current size of the stack.
     * @return The number of elements in the stack.
     */
    int size() const {
        return stk.size();
    }
};

int main() {
    int n;
    cin >> n;
    MinStack myStack(n);

    while (n--) {
        int x;
        cin >> x;
        myStack.push(x);
    }
    cout << "All input elements have been pushed to the stack, now on popping them the stack's status changes as follows:\n";
    while (!myStack.empty()) {
        cout << "Current top of stack is " << myStack.top() << " and minimum is " << myStack.getMin() << '\n';
        myStack.pop();
    }
}
// Here is a sample input:
// 7
// 8 10 13 6 14 2 20