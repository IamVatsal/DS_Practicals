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

int enqueue(struct queue* ptr, int value) {
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

int dequeue(struct queue* ptr) {
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

int peek(struct queue* ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty!");
        return -1;
    }
    else {
        return ptr->arr[(ptr->front + 1) % ptr->size];
    }
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

void qAlloc(struct queue* ptr, int size) {
    ptr->size = size;
    ptr->back = 0;
    ptr->front = 0;
    ptr->arr = (int*)malloc(ptr->size * sizeof(int));
    if (ptr->arr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    int i, size, temp;
    if (q == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // clrscr();
    printf("Enter Size of queue: ");
    scanf("%d", &size);
    qAlloc(q, size);

    for (i = 0; i < size - 1; i++) {
        printf("Push num In queue: ");
        scanf("%d", &temp);
        if (!enqueue(q, temp))
            break;
    }
    display(q);

    printf("\nDequeue: %d", dequeue(q));
    printf("\nDequeue: %d", dequeue(q));

    printf("\n");
    display(q);
    printf("\n");
    for (i = 0; i < 2; i++) {
        printf("Push num In queue: ");
        scanf("%d", &temp);
        enqueue(q, temp);
    }
    display(q);

    // getch();
    free(q->arr);
    free(q);
    return 0;
}