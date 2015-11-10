/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
private:
    int length;
    int top;
    T *container;
public:
    Stack(int length) {
        this->length = length;
        this->top = 0;
        this->container = new T[this->length];
    }

    void push(T item) {
        if(this->top <= this->length) {
            this->container[this->top++] = item;
        }
    }

    T pop() {
        return top != 0 ? this->container[--this->top] : NULL;
    }

    T peek() {
        return this->container[this->top-1];
    }

    int size() {
        return this->top;
    }

    int getLength() {
        return this->length;
    }
};

#endif // STACK_H
