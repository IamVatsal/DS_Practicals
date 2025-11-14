#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data);
int insertAtFirst(struct Node** head, int data);
int deleteAtFirst(struct Node** head);
int insertAtLast(struct Node** head, int data);
int deleteAtLast(struct Node** head);
int insertAfterspecifiednode(struct Node** head, int pos, int data);
int deleteAfterspecifiednode(struct Node** head, int pos);
void Traverse(struct Node* head);

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}


int insertAtFirst(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
        return 0;
    }
    struct Node* temp = *head;
    node->next = *head;
    temp->prev = node;
    *head = node;
    return 0;
}

int deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return -1;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    return 0;
}

int insertAtLast(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
        return 0;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
    return 0;
}

int deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return -1;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return 0;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return 0;
}

int insertAfterspecifiednode(struct Node** head, int pos, int data) {
    if (pos == 0) {
        insertAtFirst(head, data);
        return 0;
    }
    struct Node* temp = *head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds.\n");
            return -1;
        }
        temp = temp->next;
    }
    struct Node* node = createNode(data);
    node->next = temp->next;
    node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = node;
    }
    temp->next = node;
    return 0;
}

int deleteAfterspecifiednode(struct Node** head, int pos) {
    if (pos == 0) {
        deleteAtFirst(head);
        return 0;
    }
    struct Node* temp = *head;
    for (int i = 0; i < pos; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds.\n");
            return -1;
        }
        temp = temp->next;
    }
    struct Node* deletionNode = temp->next;
    if (deletionNode == NULL) {
        printf("No node to delete after the specified position.\n");
        return -1;
    }
    temp->next = deletionNode->next;
    if (deletionNode->next != NULL) {
        deletionNode->next->prev = temp;
    }
    free(deletionNode);
    return 0;
}


void Traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* doublyLL = NULL;

    // Testing InsertAtLast
    insertAtLast(&doublyLL, 20);
    Traverse(doublyLL);
    insertAtLast(&doublyLL, 30);
    Traverse(doublyLL);

    // Testing InsertAtFirst
    insertAtFirst(&doublyLL, 10);
    Traverse(doublyLL);
    insertAtFirst(&doublyLL, 5);
    Traverse(doublyLL);

    // Testing InsertAfterspecifiednode
    insertAfterspecifiednode(&doublyLL, 2, 25);
    Traverse(doublyLL);

    // Testing DeleteAfterspecifiednode
    deleteAfterspecifiednode(&doublyLL, 2);
    Traverse(doublyLL);

    // Testing DeleteAtFirst
    deleteAtFirst(&doublyLL);
    Traverse(doublyLL);

    // Testing DeleteAtLast
    deleteAtLast(&doublyLL);
    Traverse(doublyLL);

    // Free the entire list
    freeList(&doublyLL);
    
    return 0;
}