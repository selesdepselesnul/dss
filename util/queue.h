#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>
#include <algorithm>

// Abstract Queue
template<class T>
class Queue {
protected:
    int length;
    T* container;
    int head;
    int tail;
    void initCounter() {
        this->head = 0;
        this->tail = 0;
    }

    virtual void doEnqueue(T item) { this->container[this->tail++] = item; }
    virtual T doDequeue() { return this->container[this->head++]; }
public:
    Queue(int length) {
        initCounter();
        this->container = new T[length];
        this->length = length;
    }

    virtual int size() { return this->tail - this->head;}

    virtual void enqueue(T item) {
        if(!this->isFull()) doEnqueue(item);
    }

    virtual T dequeue() {
        return !this->isEmpty() ? doDequeue() : NULL;
    }

    virtual bool isFull() { return this->tail == this->length; }
    virtual bool isEmpty() { return this->tail == this->head; }
    int getLength() { return this->length; }
    int getTail() { return this->tail;}
    int getHead() { return this->head;}
};

// Reset Queue
template<class T>
class ResetQueue : public Queue<T> {
public:
    ResetQueue(int length): Queue<T>(length){}
public:
    T doDequeue() {
        T item = Queue<T>::doDequeue();
        if(this->isEmpty())
            this->initCounter();
        return item;
    }
};

// Shifting Queue
template<class T>
class ShiftingQueue : public Queue<T> {
public:
    ShiftingQueue(int length) : Queue<T>(length) {}
protected:
    T doDequeue() {
       T item = this->container[this->head];
       for (int i = 0; i < this->tail - 1; i++)
           this->container[i] = this->container[i+1];
       this->tail--;
       return item;
    }
};

// Circular Queue
template<class T>
class CircularQueue : public Queue<T> {
private:
    int counter;
public:
    CircularQueue(int length) : Queue<T>(length){ this->counter = 0;}

public:
    bool isFull() { return this->counter == this->length;}
    bool isEmpty() { return this->counter == 0; }
    int size() { return this->counter; }

protected:
    void doEnqueue(T item) {
        this->counter++;
        if(this->tail == this->length)
            this->tail = 0;
        this->container[this->tail++] = item;
    }


    T doDequeue() {
        T item = this->container[this->head++];
        this->counter--;
        if(this->head == this->length)
            this->head = 0;
        return item;
    }



};

#endif // QUEUE_H
