 #include <stdio.h>
 #include <conio.h>
 int fibo(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
	else {
        return fibo(x-1)+fibo(x-2);
    }
 }


 int main (){
	int n;
	clrscr();
	printf("Enter an integer: ");
    scanf("%d", &n);
    int ans = fibo(n);
    printf("The nth term of fibonacci series is %d.\n", ans);
	getch();
	return 0;
 }