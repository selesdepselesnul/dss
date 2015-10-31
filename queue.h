#ifndef QUEUE_H
#define QUEUE_H


template<class T>
class Queue {
protected:
    int length;
    T* container;
    int size;
    int head;
    int tail;
public:
    Queue(int length) {
        this->length = length;
        this->container = new T[length];
        this->size = 0;
    }

    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    int getSize() { return this->size; }
    bool isFull() {}
};

template<class T>
class SimpleQueue : public Queue<T> {
public:
    SimpleQueue(int length): Queue<T>(length){}

    void enqueue(T item) {
        this->container[this->size] = item;
    }
    T dequeue() {
        return this->container[this->size];
    }
};

#endif // QUEUE_H
