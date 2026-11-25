#include <iostream>
#include "stack.h"
#include "queue.h"

int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    while (!st.empty()) {
        std::cout << st.top() << " "; 
        st.pop();
    }
    std::cout << "\n\n";

    Queue<int> q(2); 
    q.push(10);
    q.push(20);
    q.push(30); 
    
    while (!q.empty()) {
        std::cout << q.front() << " "; 
        q.pop();
    }
    std::cout << "\n";

    return 0;
}