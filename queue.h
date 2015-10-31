#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>


// Base Abstract Queue
template<class T>
class Queue {
private:
    const int INVALID_ACCESS = -1;
protected:
    int length;
    T* container;
    int head;
    int tail;
    void initCounter() {
        this->head = -1;
        this->tail = -1;
    }
public:
    Queue(int length) {
        initCounter();
        this->container = new T[length];
        this->length = length;
    }

    virtual int size() = 0;
    void enqueue(T item) {
        if(this->head == - 1 || !this->isFull())
            this->container[++this->tail] = item;
    }
    T dequeue() { return !this->isEmpty() ? this->container[++this->head] : NULL; }
    bool isFull() { return size() == this->length || size() == INVALID_ACCESS; }
    bool isEmpty() { return size() == 0 || size() == INVALID_ACCESS; }
    int getLength() { return this->length; }
    int getTail() { return this->tail;}
    int getHead() { return this->head;}
};

// SimpleQueue
template<class T>
class SimpleQueue : public Queue<T> {
public:
    SimpleQueue(int length): Queue<T>(length){}
    int size() {
        return (this->tail == this->head) && (this->head != -1)
                ? -1 : this->tail - this->head;
    }
};

// Reset Queue
template<class T>
class ResetQueue : public Queue<T> {
public:
    ResetQueue(int length): Queue<T>(length){}
public:
    int size() {
        if(this->tail  == this->head) {
            this->initCounter();
            return 0;
        } else {
            return this->tail - this->head;
        }
    }
};

// Circular Queue
template<class T>
class CircularQueue : public Queue<T> {
public:
    CircularQueue(int length) : Queue<T>(length){}
    int size() {
        return this->tail - this->head;
    }
};


#endif // QUEUE_H
