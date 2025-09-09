#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	int size;
	int top;
	char* arr;
};

int isEmpty(struct stack *ptr){
	return ptr->top == -1;
}

int isFull(struct stack *ptr){
    return ptr->top == ptr->size-1;
}

char push(struct stack *ptr,char value){
	if(!isFull(ptr)){
		ptr->top++;
		ptr->arr[ptr->top] = value;
		return 1;
	}else{
		printf("\nStack Overflowed: stack is full!");
		return 0;
	}
}

char pop(struct stack *ptr){
    if(!isEmpty(ptr)){
	char temp = ptr->arr[ptr->top];
	ptr->arr[ptr->top--] = 0;
	return temp;
    }else{
	printf("\nStack Underflowed: stack is empty!");
	return -1;
    }
}

char peek(struct stack *ptr){
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
		printf("%c ", ptr->arr[i]);
	}
}
void sAlloc(struct stack *ptr,int size){
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (char *) malloc(ptr->size * sizeof(char));
	if (ptr->arr == NULL) {
		printf("Memory allocation failed");
		exit(1);
	}
}
char precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int main() {
    struct stack *op = (struct stack*) malloc(sizeof(struct stack));
    char str[100] = "1+2*3^4+5";
    char postfix[100];
    int i = 0, k = 0;

    sAlloc(op, 100);
    // clrscr();
    printf("Infix: %s\n", str);

    while (str[i] != '\0') {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(op, ch);
        } else if (ch == ')') {
            while (!isEmpty(op) && peek(op) != '(') {
                postfix[k++] = pop(op);
            }
            pop(op); // Remove '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!isEmpty(op) && precedence(peek(op)) >= precedence(ch)) {
                postfix[k++] = pop(op);
            }
            push(op, ch);
        }
        i++;
    }
    while (!isEmpty(op)) {
        postfix[k++] = pop(op);
    }
    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
    // getch();
    free(op->arr);
    free(op);
    return 0;
}