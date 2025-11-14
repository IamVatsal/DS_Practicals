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
    if (*head == NULL) {
        node->next = node;
        *head = node;
        return 0;
    }
    // Find last node to update its next pointer
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    node->next = *head;
    temp->next = node;
    *head = node;
    return 0;
}

int deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return -1;
    }
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return 0;
    }

    // Find the last node
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    last->next = *head;
    free(temp);
    return 0;
}

int insertAtLast(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        node->next = node;
        *head = node;
        return 0;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = node;
    node->next = *head;
    return 0;
}

int deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return -1;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return 0;
    }

    struct Node* temp = *head;
    while (temp->next->next != *head) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = *head;

    return 0;
}

int insertAfterspecifiednode(struct Node** head, int pos, int data) {
    if (pos == 0) {
        insertAtFirst(head, data);
        return 0;
    }
    struct Node* temp = *head;
    for (int i = 0; i < pos; i++) {
        if (temp->next == *head) {
            printf("Position out of bounds\n");
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
        if (temp->next == *head) {
            printf("Position out of bounds\n");
            return -1;
        }
        temp = temp->next;
    }
    struct Node* deletionNode = temp->next;
    temp->next = deletionNode->next;
    free(deletionNode);
    return 0;
}


void Traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

void freeList(struct Node** head) {
    if (*head == NULL) {
        return;  // Nothing to free
    }
    
    struct Node* current = *head;
    struct Node* first = *head;
    struct Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != first);
    *head = NULL;
}

int main() {
    struct Node* circularLL = NULL;

    // Testing InsertAtLast
    insertAtLast(&circularLL, 20);
    Traverse(circularLL);
    insertAtLast(&circularLL, 30);
    Traverse(circularLL);

    // Testing InsertAtFirst
    insertAtFirst(&circularLL, 10);
    Traverse(circularLL);
    insertAtFirst(&circularLL, 5);
    Traverse(circularLL);

    // Testing InsertAfterspecifiednode
    insertAfterspecifiednode(&circularLL, 2, 25);
    Traverse(circularLL);

    // Testing DeleteAfterspecifiednode
    deleteAfterspecifiednode(&circularLL, 2);
    Traverse(circularLL);

    // Testing DeleteAtFirst
    deleteAtFirst(&circularLL);
    Traverse(circularLL);

    // Testing DeleteAtLast
    deleteAtLast(&circularLL);
    Traverse(circularLL);

    // Free the entire list
    freeList(&circularLL);

    return 0;
}