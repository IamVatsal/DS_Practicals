 #include <stdio.h>
 #include <conio.h>

 int main (){
	int a[5];
    int sum = 0;
    float avg;
	// clrscr();
	printf("Enter 5 numbers:\n");
    int i;
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    printf("The numbers are:\n");
    for(i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
    int min = a[0];
    int max = a[0];
    for(i=1;i<5;i++){
        if(min > a[i]){
        	min = a[i];
		}
		if(max < a[i]){
        	max = a[i];
		}
    }
    for(i=0;i<5;i++){
        sum +=a[i];
    }
    avg = sum/5;
    printf("\nThe Minimum value of array is %d\n",min);
    printf("The Maximum value of array is %d\n",max);
    printf("The average of value of array is %f\n",avg);
	// getch();
	return 0;
 }