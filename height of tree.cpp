#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Function to calculate the height of a binary tree
int calculateHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    int n, data;

    // Input the number of nodes
    printf("Enter the number of nodes");
    scanf("%d", &n);

    // Handle empty tree
    if (n == 0) {
        printf("The tree is empty\n");
        return 0;
    }

    // Input node values and build the tree
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Calculate and display the height of the tree
    int height = calculateHeight(root);
    printf("The height of the binary tree is: %d\n", height);

    return 0;
}

