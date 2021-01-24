// Copyright 2020 VladimirUspensky
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
private:
    int current_size{};
    int max_size{};
    T* stack;
public:
    MyStack(const MyStack& stack) {
        this->current_size = stack.current_size;
        this->stack = stack.stack;
        this->max_size = stack.max_size;
    }

    ~MyStack() {
        delete[] this->stack;
    }

    T push(T el) {
        if (!isFull()) {
            this->stack[this->current_size] = el;
            this->current_size++;
            return el;
        }
            return -1;
    }

    T get() {
        if (!isEmpty()) return this->stack[this->current_size - 1];
        return -1;
    }


    T pop() {
        if (!isEmpty()) {
            this->current_size --;
            return this->stack[this->current_size];
        }
        return -1;
    }

    bool isFull() {
        if (this->current_size == this->max_size) return true;
        return false;
    }

    bool isEmpty() {
        if (this->current_size == 0) return true;
        return false;
    }

    explicit MyStack(int stack_size) {
        this->max_size = stack_size;
        this->current_size = 0;
        this->stack = new T[stack_size];
    }
};

#endif  // INCLUDE_MYSTACK_H_
