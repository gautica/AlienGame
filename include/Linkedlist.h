#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct node
{
    T data;
    node* previous;
    node* next;
};

template <class E>
class Linkedlist {
private:
    node<E>* head;
    node<E>* tail;
public:
    Linkedlist() {
        head = nullptr;
        tail = nullptr;
    }
    int getLength();
    //template <typename T>
    node<E>* first();
    node<E>* last();
    void insert(E &data);
    void append(E &data);
    int deleteNode(E &data);
    template<typename T>
    friend std::ostream& operator<<(std::ostream &out, Linkedlist<T> &list);
};

template<class E>
node<E>* Linkedlist<E>::first() {
    return head;
}

template<class E>
node<E>* Linkedlist<E>::last() {
    return tail;
}

template <class E>
void Linkedlist<E>::insert(E &data) {
    node<E>* temp = new node<E>;
    temp->data = data;
    temp->previous = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp = nullptr;
    } else {
        temp->next = head;
        head->previous = temp;
        head = temp;
        temp = nullptr;
    }
}

template<class E>
void Linkedlist<E>::append(E &data) {
    node<E>* temp = new node<E>;
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

template<class E>
int Linkedlist<E>::deleteNode(E &data) {
    if (head == nullptr) {
        return -1;
    }
    if (head->data == data) {
        head = head->next;
        return 0;
    }
    if (tail->data == data) {
        tail = tail->previous;
        return 0;
    }
    node<E>* temp = head->next;
    while (temp->data != data) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return -1;
    } else {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        return 0;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream &out, Linkedlist<T> &list) {
    node<T>* temp = list.first();
    while (temp != nullptr) {
        out << temp->data << " ";
        temp = temp->next;
    }
    return out;
}

#endif
