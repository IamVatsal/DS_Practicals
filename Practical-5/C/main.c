#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int back;
    int* arr;
};

int isEmpty(struct queue* ptr) { return ptr->front == ptr->back; }

int isFull(struct queue* ptr) {
    return (ptr->back + 1) % ptr->size == ptr->front;
}

void display(struct queue* ptr) {
    int i;
    printf("\nQueue: ");
    if (!isEmpty(ptr)) {
        for (i = (ptr->front + 1) % ptr->size; i != (ptr->back + 1) % ptr->size;
            i = (i + 1) % ptr->size) {
            printf("%d ", ptr->arr[i]);
        }
    }
}

int peek(struct queue* ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty!");
        return -1;
    }
    else {
        return ptr->arr[(ptr->front + 1) % ptr->size];
    }
}

void qAlloc(struct queue* ptr, int size) {
    ptr->size = size;
    ptr->back = 0;
    ptr->front = 0;
    ptr->arr = (int*)malloc(ptr->size * sizeof(int));
    if (ptr->arr == NULL) {
        printf("Memory allocation Failed");
        exit(1);
    }
}

int insertAtRear(struct queue* ptr, int value) {
    if (!isFull(ptr)) {
        ptr->back = (ptr->back + 1) % ptr->size;
        ptr->arr[ptr->back] = value;
        return 1;
    }
    else {
        printf("\nQueue Overflowed: Queue is full!");
        return 0;
    }
}

int insertAtFront(struct queue* ptr, int value) {
    if (!isFull(ptr)) {
        ptr->arr[ptr->front] = value;
        ptr->front = (ptr->front - 1 + ptr->size) % ptr->size;
        return 1;
    }
    else {
        printf("\nQueue Overflowed: Queue is full!");
        return 0;
    }
}

int deleteAtFront(struct queue* ptr) {
    int temp;
    if (!isEmpty(ptr)) {
        ptr->front = (ptr->front + 1) % ptr->size;
        temp = ptr->arr[ptr->front];
        return temp;
    }
    else {
        printf("\nQueue Underflowed: Queue is empty!");
        return -1;
    }
}

int deleteAtRear(struct queue* ptr) {
    int temp;
    if (!isEmpty(ptr)) {
        temp = ptr->arr[ptr->back];
        ptr->back = (ptr->back - 1 + ptr->size) % ptr->size;
        return temp;
    }
    else {
        printf("\nQueue Underflowed: Queue is empty!");
        return -1;
    }
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    int i, size, temp;
    if (q == NULL) {
        printf("Memory allocation Failed");
        return 1;
    }

    // clrscr();
    printf("Enter Size Of Queue: ");
    scanf("%d", &size);
    qAlloc(q, size);

    for (i = 0; i < size - 1; i++) {
        printf("Insert at Rear In queue: ");
        scanf("%d", &temp);
        if (!insertAtRear(q, temp))
            break;
    }
    display(q);

    printf("\nDelete at Front: %d", deleteAtFront(q));
    printf("\nDelete at Front: %d", deleteAtFront(q));
    printf("\nDelete at Front: %d", deleteAtFront(q));
    printf("\nDelete at Front: %d", deleteAtFront(q));

    printf("\n");
    display(q);
    printf("\n");
    for (i = 0; i < 2; i++) {
        printf("Insert at Front In queue: ");
        scanf("%d", &temp);
        insertAtFront(q, temp);
    }
    display(q);

    printf("\nDelete at Rear: %d", deleteAtRear(q));
    printf("\nDelete at Rear: %d", deleteAtRear(q));

    printf("\n");
    display(q);
    // getch();
    free(q->arr);
    free(q);
    return 0;
}