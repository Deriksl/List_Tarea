#include <iostream>
#include "List.h"

template<typename T>
ListNode<T>::ListNode(T value) {
    data = value;
    next = nullptr;
}

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
void List<T>::PushBack(T value) {
    // Crear un nuevo nodo con el valor especificado
    ListNode<T>* newNode = new ListNode<T>(value);

    // Si la lista está vacía, el nuevo nodo es la cabeza y la cola
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // Si la lista no está vacía, agregar el nuevo nodo al final y actualizar la cola
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template<typename T>
void List<T>::Print() {
    ListNode<T>* current = head;

    // Recorrer la lista e imprimir cada elemento
    while (current != nullptr) {
        std::cout << current->data;

        if (current->next != nullptr) {
            std::cout << ", ";
        }

        current = current->next;
    }

    std::cout << std::endl;
}

template<typename T>
List<T>::List(T* array, int arraySize) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    // Agregar cada elemento del array a la lista
    for (int i = 0; i < arraySize; i++) {
        PushBack(array[i]);
    }
}

template<typename T>
void List<T>::Reverse() {
    // Si la lista tiene 0 o 1 elementos, no se requiere inversión
    if (size <= 1) {
        return;
    }

    ListNode<T>* prevNode = nullptr;
    ListNode<T>* currentNode = head;
    ListNode<T>* nextNode = nullptr;

    // Invertir los punteros de los nodos en la lista
    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    // Actualizar la cabeza y la cola después de la inversión
    tail = head;
    head = prevNode;
}

template<typename T>
void List<T>::Unique() {
    // Si la lista tiene 0 o 1 elementos, no se requiere eliminación de duplicados
    if (size <= 1) {
        return;
    }

    ListNode<T>* current = head;

    // Eliminar los nodos duplicados de la lista
    while (current != nullptr && current->next != nullptr) {
        ListNode<T>* runner = current;

        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                ListNode<T>* duplicateNode = runner->next;
                runner->next = runner->next->next;
                delete duplicateNode;
                size--;
            }
            else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}