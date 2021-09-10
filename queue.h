//basic implementation of a QUEUE
#include <iostream>
template<class T>
class QNode{
public:
    QNode<T>(){}
    QNode<T>(T val): value{val}{}
    int value;
    QNode* next;
    QNode* prev;
};
template<class T>
class Queue{
public:
    Queue<T>(): head{nullptr}, back{nullptr}{};
    bool isEmpty();
    void enqueue(T val);
    T dequeue();
    void printQueue();
    T headq();
private:
    QNode<T>* head;
    QNode<T>* back;
    int size = 0;
};

template<class T>
bool Queue<T>::isEmpty(){
    return this->head == nullptr;
}

template<class T>
void Queue<T>::enqueue(T val){
    this->size += 1;
    QNode<T>* tmp = new QNode<T>(val);
    if(this->isEmpty()){
        this->head = this->back = tmp;
    }else{
        tmp->next = this->head;
        this->head->prev = tmp;
        this->head = tmp;
    }
}
template<class T>
T Queue<T>::dequeue(){
    if(!this->isEmpty()){
        QNode<T>* tmp = this->back;
        T value = tmp->value;
        if(this->head == this->back){
            this->head = this->back = nullptr;
            delete tmp;
            return value;
        }else{
            this->back = this->back->prev;
            delete tmp;
            return value;
        }
    }else{
        T val;
        return val;
    }
}

template<class T>
void Queue<T>::printQueue(){
    QNode<T>* tmp = this->back;
    while(tmp != 0){
        std::cout << tmp->value << '\n';
        tmp = tmp->prev;
    }
};

template<class T>
T Queue<T>::headq(){
    return this->back->value;
};