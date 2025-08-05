 #include <stdio.h>
 #include <conio.h>

 int main (){
	int arr[5],i;
	// clrscr();
	printf("Enter 5 Numbers: \n");
	for(i = 0; i < 5; i++){
		scanf("%d",&arr[i]);
	}
	printf("The Numbers are: \n");
	for(i = 0; i < 5; i++){
		printf("%d ",arr[i]);
	}
	// getch();
	return 0;
 }