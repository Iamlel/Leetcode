#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *ptr;
    int capacity;

    int head;
    int tail;
    bool full;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));

    queue->ptr = (int*) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        queue->ptr[i] = -1;
    }
    queue->capacity = k;

    queue->head = 0;
    queue->tail = 0;
    queue->full = false;

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->full) {
        return false;
    }

    obj->ptr[obj->head] = value;
    obj->head = (obj->head + 1) % obj->capacity;

    if (obj->head - obj->tail == 0) { 
        obj->full = true;
    }

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj->full && obj->head - obj->tail == 0) {
        return false;
    }

    obj->ptr[obj->tail] = -1;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->full = false;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return obj->ptr[obj->tail];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    int head = (obj->capacity + obj->head - 1) % obj->capacity;
    return obj->ptr[head];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (!obj->full && obj->head - obj->tail == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->full;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->ptr);
    free(obj);
}
