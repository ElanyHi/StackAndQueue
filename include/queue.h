#pragma once
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count; // Текущее количество элементов

    void resize() {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        T* new_data = new T[new_capacity];
        
        // Разворачиваем кольцо в плоский массив
        for (size_t i = 0; i < count; ++i) {
            new_data[i] = std::move(data[(head + i) % capacity]);
        }
        
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        head = 0;
        tail = count; // tail указывает на первую свободную ячейку
    }

public:
    Queue(size_t initial_capacity = 10) 
        : capacity(initial_capacity), head(0), tail(0), count(0) {
        data = new T[capacity];
    }

    ~Queue() { 
        delete[] data; 
    }

    // Запрещаем копирование, чтобы избежать утечек
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    void push(const T& value) {
        if (count == capacity) resize();
        data[tail] = value;
        tail = (tail + 1) % capacity; // Закольцовываем индекс добавления
        count++;
    }

    void pop() {
        if (empty()) throw std::out_of_range("Queue is empty");
        head = (head + 1) % capacity; // Закольцовываем индекс извлечения
        count--;
    }

    T& front() {
        if (empty()) throw std::out_of_range("Queue is empty");
        return data[head];
    }

    bool empty() const { 
        return count == 0; 
    }

    size_t size() const {
        return count;
    }
};