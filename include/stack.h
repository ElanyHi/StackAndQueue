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

    Node* top_node;
    size_t count;

public:
    Stack() : top_node(nullptr), count(0) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& value) {
        top_node = new Node(value, top_node);
        count++;
    }

    void pop() {
        if (empty()) throw std::out_of_range("Stack is empty");
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
        count--;
    }

    T& top() {
        if (empty()) throw std::out_of_range("Stack is empty");
        return top_node->data;
    }

    bool empty() const {
        return top_node == nullptr;
    }

    size_t size() const {
        return count;
    }
};