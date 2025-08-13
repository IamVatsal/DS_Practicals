#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int* arr;
};

int isEmpty(struct stack *ptr){
	if(ptr->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct stack *ptr){
	if(ptr->top < ptr->size-1){
		return 0;
	}
	else{
		return 1;
	}
}

int push(struct stack *ptr,int value){
	if(!isFull(ptr)){
		ptr->top++;
		ptr->arr[ptr->top] = value;
		return value;
	}else{
		printf("\nStack Overflowed: stack is full!");
		return -1;
	}
}

int pop(struct stack *ptr){
    if(!isEmpty(ptr)){
	int temp = ptr->arr[ptr->top];
	ptr->arr[ptr->top] = 0;
	ptr->top--;
	return temp;
    }else{
	printf("\nStack Underflowed: stack is empty!");
	return -1;
    }
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

	if (s == NULL) {
		printf("Memory allocation failed");
		return 1;
	}

	sAlloc(s,10);
	clrscr();
	push(s,10);
	push(s,20);
	push(s,30);
	display(s);
	pop(s);
	display(s);
	getch();
	free(s->arr);
	free(s);
	return 0;
}