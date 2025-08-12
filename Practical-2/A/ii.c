#include <stdio.h>

int main() {
    int rows, cols, i, j, element;
    int found = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    for(int i =0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Enter Value Of %d By %d: ", i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter Value to search: ");
    scanf("%d", &element);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == element) {
                printf("Element %d found at position (%d, %d)\n", element, i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }

    return 0;
}
