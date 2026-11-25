#pragma once
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val, Node* nxt = nullptr) : data(val), next(nxt) {}
    };

    Node* first;
    size_t count;

public:
    Stack() : first(nullptr), count(0) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& value) {
        first = new Node(value, first);
        count++;
    }

    void pop() {
        if (empty()) throw std::out_of_range("Stack is empty");
        Node* temp = first;
        first = first->next;
        delete temp;
        count--;
    }

    T& top() {
        if (empty()) throw std::out_of_range("Stack is empty");
        return first->data;
    }

    bool empty() const {
        return first == nullptr;
    }

    size_t size() const {
        return count;
    }
};