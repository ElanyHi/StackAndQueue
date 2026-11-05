#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED
#include <iostream>
#include <stdexcept>
#include <string>

const int FACTOR = 2;

template <typename T>
class MyVector {
private:
    size_t n = 0;
    size_t capacity = 1;
    T* data = nullptr;

public:
    class iterator {
    private:
        T* curr;
    public:
        iterator(T* _curr) : curr(_curr) {}
        T& operator*() { return *curr; }
        const T& operator*() const { return *curr; }
        iterator& operator++() { ++curr; return *this; }
        iterator operator++(int) { iterator tmp(*this); ++curr; return tmp; }
        bool operator!=(const iterator& other) const { return curr != other.curr; }
        bool operator==(const iterator& other) const { return curr == other.curr; }
    };

    class const_iterator {
    private:
        const T* curr;
    public:
        const_iterator(const T* _curr) : curr(_curr) {}
        const T& operator*() const { return *curr; }
        const_iterator& operator++() { ++curr; return *this; }
        const_iterator operator++(int) { const_iterator tmp(*this); ++curr; return tmp; }
        bool operator!=(const const_iterator& other) const { return curr != other.curr; }
        bool operator==(const const_iterator& other) const { return curr == other.curr; }
    };

    iterator begin() { return iterator(data); }
    iterator end() { return iterator(data + n); }
    const_iterator begin() const { return const_iterator(data); }
    const_iterator end() const { return const_iterator(data + n); }



    MyVector() : n(0), capacity(1), data(new T[1]) {}

    MyVector(size_t _size, const T& _value = T())
        : n(_size), capacity(_size * FACTOR), data(new T[capacity]) {
        if (capacity == 0) capacity = 1;
        for (size_t i = 0; i < n; i++) {
            data[i] = _value;
        }
    }

    MyVector(const MyVector<T>& other)
        : n(other.n), capacity(other.capacity), data(new T[capacity]) {
        for (size_t i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
    }

    MyVector<T>& operator=(const MyVector<T>& other) {
        if (this == &other) return *this;

        delete[] data;
        n = other.n;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ~MyVector() {
        delete[] data;
    }

    size_t size() const { return n; }
    size_t cap() const { return capacity; }
    bool empty() const { return n == 0; }

    void reserve(size_t newCapacity) {
        if (capacity >= newCapacity) return;

        T* tmp = new T[newCapacity];
        for (size_t i = 0; i < n; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
        capacity = newCapacity;
    }

    void push_back(const T& value) {
        if (n == capacity) {
            reserve(capacity * FACTOR);
        }
        data[n] = value;
        n++;
    }

    void pop_back() {
        if (n > 0) n--;
    }

    void insert(size_t pos, const T& value) {
        resize(n+1);
        for (size_t i = n-1; i>pos; i--){
            data[i] = data[i-1];
        }
        data[pos] = value;
    }

    void erace(size_t pos) {
        for (size_t i = pos+1;i<n;i++){
            data[i-1] = data[i];
        }
        resize(n-1);
    }

    void clear() {
        n = 0;
    }

    void shrink_to_fit() {
        if (n == capacity) return;
        size_t newCapacity = (n>0) ? n:1;
        T* tmp = new T[newCapacity];
        for (size_t i =0; i < n; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
        capacity = newCapacity;
    }

     void resize(size_t newSize, const T& value = T()) {
        if (newSize < n) {
            n = newSize;
        }
        else if (newSize > n) {
            if (newSize > capacity) {
                size_t newCapacity = newSize * FACTOR;
                reserve(newCapacity);
            }
            for (size_t i = n; i < newSize; i++) {
                data[i] = value;
            }
            n = newSize;
        }
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    T& at(size_t index) {
        if (index >= n) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= n) throw std::out_of_range("Index out of range");
        return data[index];
    }

    T& front() { return data[0]; }
    const T& front() const { return data[0]; }

    T& back() { return data[n - 1]; }
    const T& back() const { return data[n - 1]; }
};


#endif 
