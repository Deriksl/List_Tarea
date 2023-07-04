#include <iostream>
#include "List.h"

int main() {
    // Crear una lista de caracteres
    List<char> myList;
    myList.PushBack('a');
    myList.PushBack('b');
    myList.PushBack('c');

    // Imprimir la lista de caracteres
    myList.Print();

    // Crear una lista de enteros a partir de un array
    const int arraySize = 5;
    int myArray[arraySize] = { 1, 3, 5, 7, 9 };

    List<int> myIntArray(myArray, arraySize);
    myIntArray.Print();

    // Invertir la lista de enteros
    myIntArray.Reverse();
    myIntArray.Print();

    // Crear una lista de enteros con duplicados y eliminar los duplicados
    List<int> myListWithDuplicates;
    myListWithDuplicates.PushBack(1);
    myListWithDuplicates.PushBack(1);
    myListWithDuplicates.PushBack(2);
    myListWithDuplicates.PushBack(3);
    myListWithDuplicates.PushBack(4);
    myListWithDuplicates.PushBack(2);
    myListWithDuplicates.PushBack(3);
    myListWithDuplicates.PushBack(1);

    myListWithDuplicates.Unique();
    myListWithDuplicates.Print();

    return 0;
}