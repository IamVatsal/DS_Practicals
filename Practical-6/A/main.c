#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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
    return node;
}


int insertAtFirst(struct Node** head, int data) {
    struct Node* node = createNode(data);
    node->next = *head;
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
        if (temp->next == NULL) {
            printf("Position out of bounds.\n");
            return -1;
        }
        temp = temp->next;
    }
    struct Node* node = createNode(data);
    node->next = temp->next;
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
    struct Node* LL = NULL;

    // Testing InsertAtLast
    insertAtLast(&LL, 20);
    Traverse(LL);
    insertAtLast(&LL, 30);
    Traverse(LL);

    // Testing InsertAtFirst
    insertAtFirst(&LL, 10);
    Traverse(LL);
    insertAtFirst(&LL, 5);
    Traverse(LL);

    // Testing InsertAfterspecifiednode
    insertAfterspecifiednode(&LL, 2, 25);
    Traverse(LL);

    // Testing DeleteAfterspecifiednode
    deleteAfterspecifiednode(&LL, 2);
    Traverse(LL);

    // Testing DeleteAtFirst
    deleteAtFirst(&LL);
    Traverse(LL);

    // Testing DeleteAtLast
    deleteAtLast(&LL);
    Traverse(LL);
    
    // Free the entire list
    freeList(&LL);

    return 0;
}