#include "FineGrainedQueue.h"
#include <iostream>

// Реализация конструктора FineGrainedQueue
FineGrainedQueue::FineGrainedQueue() : head(nullptr) {}

// Реализация метода insertIntoMiddle
void FineGrainedQueue::insertIntoMiddle(int value, int pos) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        // Если очередь пуста, мы предполагаем, что это не должно происходить согласно условиям задачи.
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    int currentPosition = 0;

    while (current != nullptr && currentPosition < pos) {
        if (currentPosition == pos - 1) {
            break;
        }
        previous = current;
        current = current->next;
        currentPosition++;
    }

    // Если мы дошли до конца списка или нашли позицию, куда нужно вставить новый узел
    if (previous != nullptr) {
        std::lock_guard<std::mutex> lockPrev(previous->node_mutex);
        if (current != nullptr) {
            std::lock_guard<std::mutex> lockCurr(current->node_mutex);
            newNode->next = current;
            previous->next = newNode;
        }
        else {
            // Вставляем в конец списка
            previous->next = newNode;
        }
    }
}

// Реализация метода append
void FineGrainedQueue::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Реализация метода printQueue
void FineGrainedQueue::printQueue() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}