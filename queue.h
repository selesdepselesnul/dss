#ifndef QUEUE_H
#define QUEUE_H


// Base Abstract Queue
template<class T>
class Queue {
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

    virtual int getSize() = 0;
    void enqueue(T item) {
        if(this->head == - 1 || !this->isFull()) this->container[++this->tail] = item;
    }
    T dequeue() { return !this->isEmpty() ? this->container[++this->head] : NULL; }
    bool isFull() { return getSize() == this->length; }
    bool isEmpty() { return getSize() == 0; }
    int getLength() { return this->length; }
    int getTail() { return this->tail;}
    int getHead() { return this->head;}
};

// SimpleQueue
template<class T>
class SimpleQueue : public Queue<T> {
public:
    SimpleQueue(int length): Queue<T>(length){}
    int getSize() {
        return  this->tail - this->head;
    }
};

// Reset Queue
template<class T>
class ResetQueue : public Queue<T> {
public:
    ResetQueue(int length): Queue<T>(length){}
public:
    int getSize() {
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
    int getSize() {
        const int LAST_INDEX = this->length - 1;
        if(this->tail > LAST_INDEX) {
            this->tail = -1;
        } else if(this->head > LAST_INDEX) {
            this->head = -1;
        }
        return this->tail - this->head;
    }
};


#endif // QUEUE_H
