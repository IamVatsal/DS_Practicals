 #include <stdio.h>
 #include <conio.h>

 int main (){
	int a ,b ,sum = 0;
	int *p = &a,*q = &b;
	// clrscr();
	printf("Enter a and b: ");
	scanf("%d %d",&a,&b);
	sum = *p + *q;
	printf("The sum of a and b is %d",sum);
	// getch();
	return 0;
 }