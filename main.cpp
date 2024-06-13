#include "FineGrainedQueue.h"
#include <iostream>

int main() {
    FineGrainedQueue queue;

    // Добавим несколько элементов в очередь
    queue.append(1);
    queue.append(2);
    queue.append(3);
    queue.append(4);

    std::cout << "Начальная очередь: ";
    queue.printQueue();

    // Вставим элемент в середину
    queue.insertIntoMiddle(99, 2);
    std::cout << "После вставки 99 в позицию 2: ";
    queue.printQueue();

    // Вставим элемент в конец
    queue.insertIntoMiddle(100, 10); // Позиция больше длины списка
    std::cout << "После вставки 100 в позицию 10: ";
    queue.printQueue();

    return 0;
}