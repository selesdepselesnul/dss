#include "stack.h"

void Stack<T>::push(T item) {
    if(this->top <= this->length) {
        this->container[this->top++] = item;
    }
}

T Stack<T>::pop() {
        return top != 0 ? this->container[--this->top] : NULL;
}

T Stack<T>::peek() {
        return this->container[this->top-1];
 }



