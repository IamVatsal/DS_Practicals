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

char push(struct stack *ptr,char value){
	if(!isFull(ptr)){
		ptr->top++;
		ptr->arr[ptr->top] = value;
		return value;
	}else{
		printf("\nStack Overflowed: stack is full!");
		return -1;
	}
}

char pop(struct stack *ptr){
    if(!isEmpty(ptr)){
	char temp = ptr->arr[ptr->top];
	ptr->arr[ptr->top] = 0;
	ptr->top--;
	return temp;
    }else{
	printf("\nStack Underflowed: stack is empty!");
	return -1;
    }
}

char peek(struct stack *ptr){
	if(ptr->top == -1) printf("Stack is empty!");
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

int main() {
	struct stack *s = (struct stack*) malloc(sizeof(struct stack));
	char str[20] = "ababCbaba";
	int i = 0;
	if (s == NULL) {
		printf("Memory allocation failed");
		return 1;
	}

	sAlloc(s,20);
	// clrscr();
	while(str[i] != 'C' && str[i] != '\0' && str[i] != 'c'){
		if(str[i] == 'a' || str[i] == 'b'){
			push(s,str[i]);
		}
		else{
			printf("String Rejected");
			return 0;
		}
		i++;
	}
	i++;
	while(str[i] != '\0'){
		if(!isEmpty(s) && peek(s) == str[i]){
			pop(s);
		}else{
			printf("String Rejected");
			return 0;
		}
		i++;
	}
	if(isEmpty(s)){
		printf("String Accepted");
	}else{
		printf("String Rejected");
	}
	// getch();
	free(s->arr);
	free(s);
	return 0;
}