#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert operation in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find minimum value node (used in delete)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete operation in BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {  // Case 1: No child
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {  // Case 2: One child (right)
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {  // Case 2: One child (left)
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;  // Copy inorderTraversal successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// inorder Traversal (sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function with example
int main() {
    struct Node* root = NULL;

    // Creating BST by inserting values
    root = insert(root, 50);
    insert(root, 33);
    insert(root, 28);
    insert(root, 40);
    insert(root, 76);
    insert(root, 69);
    insert(root, 81);

    printf("inorder Traversal of BST: ");
    inorderTraversal(root);

    printf("\n\nDeleting 28...\n");
    root = deleteNode(root, 28);
    inorderTraversal(root);

    printf("\n\nDeleting 33...\n");
    root = deleteNode(root, 33);
    inorderTraversal(root);

    printf("\n\nDeleting 50 (root)...\n");
    root = deleteNode(root, 50);
    inorderTraversal(root);

    printf("\n");

    return 0;
}