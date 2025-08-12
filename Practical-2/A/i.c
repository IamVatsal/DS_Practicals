#include <stdio.h>

int main(){
    int rows, cols, i, j;
    int maxNum,count = 0;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];
    

    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter Value Of %d By %d: ", i,j);
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0){
                count++;
            }
        }
    }
    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if(count > maxNum/2){
        printf("Matrix is Sparse Matrix");
    }else{
        printf("Matrix is Not Sparse Matrix");
    }
    return 0;
}