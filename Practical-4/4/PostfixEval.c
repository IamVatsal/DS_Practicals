#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

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
	if(ptr->top == -1) {
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

int toInt(char ch){
    int i = ch;
    return i-48;
}

int main() {
    struct stack *num = (struct stack*) malloc(sizeof(struct stack));
    char postfix[100] = "1234^*+5+"; 
    int result = 0;
    int temp = 0;
    int i = 0, j = 0;

    sAlloc(num, 100);
    // clrscr();
    printf("Postfix: %s\n", postfix);

    while(postfix[i] != '\0'){
        char ch = postfix[i];
        if(ch >= '0' && ch <= '9'){
            int n = toInt(postfix[i]);
            push(num,n);
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            int second = pop(num);
            int first = pop(num);
            switch (ch){
            case '+': temp = first + second; break;
            case '-': temp = first - second; break;
            case '*': temp = first * second; break;
            case '/': temp = first / second; break;
            case '^':
                temp = 1;
                for(j = 0; j < second;j++){
                    temp *= first;
                }
                break;
            default:
                break;
            }
            push(num,temp);
        }
        i++;
    }
    result = pop(num);
    printf("Result: %d", result);
    // getch();
    free(num->arr);
    free(num);
    return 0;
}