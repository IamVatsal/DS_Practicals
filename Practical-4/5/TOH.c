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

// Function to print the move and update stacks
void moveDisk(struct stack *from, struct stack *to, char s, char d) {
    int disk = pop(from);
    push(to, disk);
    printf("Move disk %d from %c to %c\n", disk, s, d);
}

// Recursive Tower of Hanoi using stacks
void TOH(int n, struct stack *A, struct stack *B, struct stack *C, char s, char a, char d) {
    if (n == 1) {
        moveDisk(A, C, s, d);
        return;
    }
    TOH(n-1, A, C, B, s, d, a);
    moveDisk(A, C, s, d);
    TOH(n-1, B, A, C, a, s, d);
}

int main() {
    int n, i;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Allocate and initialize three stacks for rods A, B, C
    struct stack *A = (struct stack*) malloc(sizeof(struct stack));
    struct stack *B = (struct stack*) malloc(sizeof(struct stack));
    struct stack *C = (struct stack*) malloc(sizeof(struct stack));
    if (!A || !B || !C) {
        printf("Memory allocation failed");
        return 1;
    }
    sAlloc(A, n);
    sAlloc(B, n);
    sAlloc(C, n);

    // Fill rod A with disks (largest at bottom)
    for (i = n; i >= 1; i--) {
        push(A, i);
    }

    printf("\nSteps to solve Tower of Hanoi:\n");
    TOH(n, A, B, C, 'A', 'B', 'C');

    // Free allocated memory for stacks
    free(A->arr);
    free(B->arr);
    free(C->arr);
    free(A);
    free(B);
    free(C);

    return 0;
}