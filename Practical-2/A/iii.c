#include <stdio.h>

int main() {
    int x, y, z;
    int i, j, k;

    printf("Enter dimensions (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    int arr[x][y][z];

    printf("Enter elements of the 3D array:\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("arr[%d][%d][%d] = ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n3D Array elements are:\n\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
