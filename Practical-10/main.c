#include <stdio.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert operation using linear probing
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash Table is full! Cannot insert %d\n", key);
}

// Search operation
int search(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY)
            return -1;

        if (hashTable[newIndex] == key)
            return newIndex;
    }

    return -1;
}

// Delete operation
void deleteKey(int key) {
    int pos = search(key);

    if (pos == -1) {
        printf("%d not found, cannot delete\n", key);
    }
    else {
        hashTable[pos] = DELETED;
        printf("Deleted %d from index %d\n", key, pos);
    }
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("Index %d: DELETED\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;

    // Example operations
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);
    insert(15);

    display();

    printf("\nSearching for 25...\n");
    int pos = search(25);
    if (pos != -1) printf("Found at index %d\n", pos);
    else printf("Not found\n");

    printf("\nDeleting 20...\n");
    deleteKey(20);

    printf("\nAfter deletion:\n");
    display();

    printf("\nInserting 50...\n");
    insert(50);

    display();

    return 0;
}
