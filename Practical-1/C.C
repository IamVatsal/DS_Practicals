 #include <stdio.h>
 #include <conio.h>

 int main (){
	int a = 5;
	int *p = &a;
	clrscr();
	printf("The address of a is: %u\n",p);
	printf("The value of a is: %d\n",*p);
	getch();
	return 0;
 }