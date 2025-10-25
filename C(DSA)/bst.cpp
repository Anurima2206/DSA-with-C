#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};

struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
 if (root == NULL) {
 root = createNode(data);
 return root;
 }
 if (data < root->data) {
 root->left = insertNode(root->left, data);
 } else if (data > root->data) {
 root->right = insertNode(root->right, data);
 }
 return root;
}

void inorderTraversal(struct Node* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
 }
}

struct Node* findMin(struct Node* root) {
 while (root->left != NULL) {
 root = root->left;
 }
 return root;
}

struct Node* deleteNode(struct Node* root, int data) {
 if (root == NULL) {
 return root;
 }
 if (data < root->data) {
 root->left = deleteNode(root->left, data);
 } else if (data > root->data) {
 root->right = deleteNode(root->right, data);
 } else {

 if (root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }

 struct Node* temp = findMin(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
int main() {
 struct Node* root = NULL;
 int choice, data;
 while (1) {
 printf("\nBinary Search Tree Operations:\n");
 printf("1. Insert Node\n");
 printf("2. Inorder Traversal\n");
 printf("3. Delete Node\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data to insert: ");
 scanf("%d", &data);
 root = insertNode(root, data);
 break;
 case 2:
 printf("Inorder Traversal: ");
 inorderTraversal(root);
 printf("\n");
 break;
 case 3:
 printf("Enter data to delete: ");
 scanf("%d", &data);
 root = deleteNode(root, data);
 break;
 case 4:
 exit(0);
 default:
 printf("Invalid choice! Please try again.\n");
 }
 }
 return 0;
}

