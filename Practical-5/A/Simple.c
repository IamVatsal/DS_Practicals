#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct queue {
	int size;
	int top;
	int* arr;
};

int isEmpty(struct queue *ptr){
	return ptr->top == -1;
}

int isFull(struct queue *ptr){
    return ptr->top == ptr->size-1;
}

int enqueue(struct queue *ptr,int value){
	if(!isFull(ptr)){
		ptr->top++;
		ptr->arr[ptr->top] = value;
		return 1;
	}else{
		printf("\nQueue Overflowed: Queue is full!");
		return 0;
	}
}

int dequeue(struct queue *ptr){
    int i;
    if(!isEmpty(ptr)){
	int temp = ptr->arr[0];
    for(i=0; i < ptr->top;i++){
        ptr->arr[i] = ptr->arr[i+1];    
    }
	ptr->arr[ptr->top--] = 0;
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
	else return ptr->arr[0];
}

void display(struct queue *ptr){
	int i;
	printf("\nQueue: ");
	for(i = 0;i < ptr->top+1; i++){
		printf("%d ", ptr->arr[i]);
	}
	printf("\n");
}

void sAlloc(struct queue *ptr,int size){
	ptr->size = size;
	ptr->top = -1;
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

    printf("\nDequeue: %d\n",dequeue(q));

    display(q);

	// getch();
	free(q->arr);
	free(q);
	return 0;
}