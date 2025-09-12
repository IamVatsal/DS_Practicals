#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct queue {
	int size;
    int front;
	int end;
	int* arr;
};

int isEmpty(struct queue *ptr){
    if(ptr->front == -1 && ptr->end == -1) return 1;
	return ptr->end == ptr->front - 1;
}

int isFull(struct queue *ptr){
    return ptr->end == ptr->size-1;
}

int enqueue(struct queue *ptr,int value){
	if(!isFull(ptr)){
		ptr->end++;
		ptr->arr[ptr->end] = value;
		return 1;
	}else{
		printf("\nQueue Overflowed: Queue is full!");
		return 0;
	}
}

int dequeue(struct queue *ptr){
    int i;
    if(!isEmpty(ptr)){
	    int temp = ptr->arr[ptr->front++];
	    return temp;
    }else{
	    printf("\nQueue Underflowed: Queue is empty!");
	return -1;
    }
}

int peek(struct queue *ptr){
	if(isEmpty(ptr)){
		printf("Queue is empty!");
		return -1;
	}
	else return ptr->arr[ptr->front];
}

void display(struct queue *ptr){
	int i;
	printf("\nQueue: ");
	for(i = ptr->front; i < ptr->end+1; i++){
		printf("%d ", ptr->arr[i]);
	}
}

void sAlloc(struct queue *ptr,int size){
	ptr->size = size;
	ptr->end = -1;
    ptr->front = -1;
	ptr->arr = (int *) malloc(ptr->size * sizeof(int));
	if (ptr->arr == NULL) {
		printf("Memory allocation failed");
		exit(1);
	}
}

int main() {
	struct queue *q = (struct queue*) malloc(sizeof(struct queue));
	int i,size,temp;
	if (q == NULL) {
		printf("Memory allocation failed");
		return 1;
	}

	// clrscr();
	printf("Enter Size of queue: ");
	scanf("%d",&size);
	sAlloc(q,size);

	for(i = 0; i < size; i++){
		printf("Push Num In queue: ");
		scanf("%d",&temp);
		enqueue(q,temp);
	}
    display(q);

    printf("\nDequeue: %d",dequeue(q));
    printf("\nDequeue: %d",dequeue(q));
    printf("\nDequeue: %d",dequeue(q));
    printf("\nDequeue: %d",dequeue(q));

    display(q);

	// getch();
	free(q->arr);
	free(q);
	return 0;
}