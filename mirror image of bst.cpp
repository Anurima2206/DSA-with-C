#include <stdio.h>
#include <stdlib.h>

// Define a structure for the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Function to create the mirror image of a binary tree
Node* mirrorTree(Node* root) {
    if (root == NULL) return NULL;

    // Recursively mirror the left and right subtrees
    Node* mirroredLeft = mirrorTree(root->right);
    Node* mirroredRight = mirrorTree(root->left);

    // Create a new node for the mirrored tree
    Node* mirroredNode = createNode(root->data);
    mirroredNode->left = mirroredLeft;
    mirroredNode->right = mirroredRight;

    return mirroredNode;
}

// Function to perform in-order traversal of a binary tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, data;
	// Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input node values and build the original tree
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Display the original tree (in-order traversal)
    printf("In-order traversal of the original tree: ");
    inorderTraversal(root);
    printf("\n");

    // Create the mirror image of the tree
    Node* mirroredRoot = mirrorTree(root);

    // Display the mirrored tree (in-order traversal)
    printf("In-order traversal of the mirrored tree: ");
    inorderTraversal(mirroredRoot);
    printf("\n");

    return 0;
}

