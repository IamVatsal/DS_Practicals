#include <stdio.h>

int main() {
    int i, size, sum;
    size = 4;
    sum = (3 - 1 + size) % size;
    printf("%d\n", sum);
    return 0;
}