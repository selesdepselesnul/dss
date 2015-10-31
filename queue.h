#ifndef QUEUE_H
#define QUEUE_H


template<class T>
class Queue {
protected:
    int length;
    T* container;
    int head;
    int tail;
public:
    Queue(int length) {
        this->length = length;
        this->container = new T[length];
        this->size = 0;
        this->head = 0;
        this->tail = -1;
    }

    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    int getSize() { return (this->tail - this->head) + 1; }
    bool isFull() { return head > tail && (size != 0); }
    bool isEmpty() { return head > tail && (size == 0); }
};

template<class T>
class SimpleQueue : public Queue<T> {
public:
    SimpleQueue(int length): Queue<T>(length){}

    void enqueue(T item) {
        if(!isFull()) this->container[++this->tail] = item;

    }
    T dequeue() { !isEmpty() ? this->container[this->head++] : NULL; }
};

#endif // QUEUE_H
