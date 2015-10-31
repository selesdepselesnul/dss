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
    void init() {
        this->head = 0;
        this->tail = -1;
    }
public:
    Queue(int length) {
        this->container = new T[length];
        this->length = length;
        init();
    }

    virtual int getSize() = 0;
    void enqueue(T item) { if(!this->isFull()) this->container[++this->tail] = item; }
    T dequeue() { return !this->isEmpty() ? this->container[this->head++] : NULL; }
    bool isFull() { return getSize() == this->length; }
    bool isEmpty() { return getSize() == 0; }
    int getLength() { return this->length; }
};

// SimpleQueue
template<class T>
class SimpleQueue : public Queue<T> {
public:
    SimpleQueue(int length): Queue<T>(length){}
    int getSize() {
        return (this->head > this->tail) && this->head == this->length ?
                    0 : (this->tail - this->head) + 1;
    }
};

// Reset Queue
template<class T>
class ResetQueue : public Queue<T> {
public:
    ResetQueue(int length): Queue<T>(length){}
public:
    int getSize() {
        if((this->head > this->tail) && this->head == this->length) {
            this->init();
            return 0;
        } else {
            return (this->tail - this->head) + 1;
        }

    }
};


#endif // QUEUE_H
