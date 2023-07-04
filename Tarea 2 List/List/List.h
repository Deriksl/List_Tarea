#ifndef LIST_H
#define LIST_H

template<typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    // Constructor de ListNode
    ListNode(T value);
};

template<typename T>
class List {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;

public:
    // Constructor de List
    List();
    // Agregar un elemento al final de la lista
    void PushBack(T value);
    // Imprimir la lista
    void Print();
    // Constructor de List que recibe un array y su tamaño
    List(T* array, int arraySize);
    // Invertir la lista
    void Reverse();
    // Eliminar los duplicados de la lista
    void Unique();
};

#include "List.cpp"
#endif