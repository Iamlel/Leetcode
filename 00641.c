#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* ptr;
    int capacity;

    int head;
    int tail;

    bool full;
    bool empty;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deque = malloc(sizeof(MyCircularDeque));

    deque->ptr = malloc(k * sizeof(int));
    deque->capacity = k;

    deque->head = 0;
    deque->tail = -1;
    
    deque->full = false;
    deque->empty = true;
    
    return deque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->full) {
        return false;
    }
    
    obj->ptr[obj->head] = value;
    obj->head = (obj->capacity + obj->head - 1) % obj->capacity;

    if (obj->empty) {
        obj->tail++;
        obj->empty = false;
    }

    obj->full = (obj->head - obj->tail == 0);

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->full) {
        return false;
    }

    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->ptr[obj->tail] = value;

    if (obj->empty) {
        obj->head = obj->capacity - 1;
        obj->empty = false;
    }

    obj->full = (obj->head - obj->tail == 0);

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->empty) {
        return false;
    }

    obj->head = (obj->head + 1) % obj->capacity;

    if (obj->head - obj->tail == 0) {
        obj->head = 0;
        obj->tail = -1;
        obj->empty = true;
    }

    obj->full = false;

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->empty) {
        return false;
    }

    obj->tail = (obj->capacity + obj->tail - 1) % obj->capacity;

    if (obj->head - obj->tail == 0) {
        obj->head = 0;
        obj->tail = -1;
        obj->empty = true;      
    }

    obj->full = false;

    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return (obj->empty) ? -1 : obj->ptr[(obj->head + 1) % obj->capacity];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return (obj->empty) ? -1 : obj->ptr[obj->tail];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->empty);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->full);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->ptr);
    free(obj);
}
