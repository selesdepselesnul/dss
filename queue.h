#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>
#include <algorithm>


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

    virtual int size() { return this->tail - this->head;}
    virtual void enqueue(T item) {
        if(!this->isFull()) this->container[++this->tail] = item;
    }
    virtual T dequeue() { return !this->isEmpty() ? this->container[++this->head] : NULL; }
    virtual bool isFull() { return size() == this->length; }
    virtual bool isEmpty() { return size() == 0; }
    int getLength() { return this->length; }
    int getTail() { return this->tail;}
    int getHead() { return this->head;}
};

// SimpleQueue
template<class T>
class SimpleQueue : public Queue<T> {
private:
    const int INVALID_ACCESS = -9999;
public:
    SimpleQueue(int length): Queue<T>(length){}
    int size() {
        return (this->tail == this->head) && (this->head != -1)
                ? this->INVALID_ACCESS : Queue<T>::size();
    }

    bool isFull() { return Queue<T>::isFull() || this->size() == INVALID_ACCESS; }

    bool isEmpty() { return Queue<T>::isEmpty() || this->size() == INVALID_ACCESS; }
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
            return Queue<T>::size();
        }
    }
};

// Shifting Queue
template<class T>
class ShiftingQueue : public Queue<T> {
public:
    ShiftingQueue(int length) : Queue<T>(length) {this->head = 0;}

    virtual T dequeue() {
        std::rotate(this->container, &this->container[1], &this->container[this->size() - 1]);
        return !this->isEmpty() ? this->container[this->head] : NULL;
    }


};

// Circular Queue
template<class T>
class CircularQueue : public Queue<T> {
private:
    int counter;
public:
    CircularQueue(int length) : Queue<T>(length){ this->counter = 0;}

    void enqueue(T item) {
        checkPos();
        if(this->counter != this->length) {
            ++this->counter;
            this->container[++this->tail] = item;
        }
    }

    T dequeue() {
        checkPos();
        if(this->counter != 0) {
            --this->counter;
            return this->container[++this->head];
        } else {
            return NULL;
        }
    }

    void checkPos() {
        if(this->counter != this->length) {
            qDebug() << "inside";
            if(this->tail == this->length - 1) {
                this->tail = -1;
            } else if(this->head == this->length - 1) {
                this->head = -1;
            }
        }
    }

    int size() {
        return this->counter;
    }

};

#endif // QUEUE_H
