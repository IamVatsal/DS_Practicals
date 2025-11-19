#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11
#define EMPTY -1      

int hashTable[TABLE_SIZE];
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    } 
}

void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d inserted at index %d.\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d.\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }
    printf("Key %d not found in the hash table.\n", key);
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            hashTable[index] = EMPTY;
            printf("Key %d deleted from index %d.\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }
    printf("Key %d not found in the hash table.\n", key);
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int choice, key;
    initializeTable();
    printf("Hash Table Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    while(choice != 5){
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
