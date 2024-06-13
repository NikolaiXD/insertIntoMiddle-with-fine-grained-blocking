#ifndef FINE_GRAINED_QUEUE_H
#define FINE_GRAINED_QUEUE_H

#include <mutex>

// Определение структуры Node
struct Node {
    int value;
    Node* next;
    std::mutex node_mutex;

    Node(int val) : value(val), next(nullptr) {}
};

// Определение класса FineGrainedQueue
class FineGrainedQueue {
public:
    FineGrainedQueue();
    void insertIntoMiddle(int value, int pos);
    void append(int value);
    void printQueue();

private:
    Node* head;
    std::mutex queue_mutex;
};

#endif // FINE_GRAINED_QUEUE_H