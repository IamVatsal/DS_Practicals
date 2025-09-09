#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int* arr;
};

int isEmpty(struct stack *ptr){
	return ptr->top == -1;
}

int isFull(struct stack *ptr){
    return ptr->top == ptr->size-1;
}

int push(struct stack *ptr,int value){
	if(!isFull(ptr)){
		ptr->top++;
		ptr->arr[ptr->top] = value;
		return 1;
	}else{
		printf("\nStack Overflowed: stack is full!");
		return 0;
	}
}

int pop(struct stack *ptr){
    if(!isEmpty(ptr)){
	int temp = ptr->arr[ptr->top];
	ptr->arr[ptr->top--] = 0;
	return temp;
    }else{
	printf("\nStack Underflowed: stack is empty!");
	return -1;
    }
}

int peek(struct stack *ptr){
	if(isEmpty(ptr)){
		printf("Stack is empty!");
		return -1;
	}
	else return ptr->arr[ptr->top];
}

void display(struct stack *ptr){
	int i;
	printf("\nStack: ");
	for(i = 0;i < ptr->top+1; i++){
		printf("%d ", ptr->arr[i]);
	}
}

void sAlloc(struct stack *ptr,int size){
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (int *) malloc(ptr->size * sizeof(int));
	if (ptr->arr == NULL) {
		printf("Memory allocation failed");
		exit(1);
	}
}

int main() {
	struct stack *s = (struct stack*) malloc(sizeof(struct stack));
	int i,size,temp;
	if (s == NULL) {
		printf("Memory allocation failed");
		return 1;
	}

	// clrscr();
	printf("Enter Size of Stack: ");
	scanf("%d",&size);
	sAlloc(s,size);

	for(i = 0; i < size; i++){
		printf("Push Num In Stack: ");
		scanf("%d",&temp);
		push(s,temp);
	}
	display(s);
	pop(s);
	printf("\nAfter poping one Time:");
	display(s);
	printf("\nPeek: %d",peek(s));
	// getch();
	free(s->arr);
	free(s);
	return 0;
}