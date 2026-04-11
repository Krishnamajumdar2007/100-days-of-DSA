#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue node structure for level order construction
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Create a new tree node
struct TreeNode* newTreeNode(int data) {
    if (data == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue a tree node
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    qNode->treeNode = node;
    qNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = qNode;
        return;
    }
    q->rear->next = qNode;
    q->rear = qNode;
}

// Dequeue a tree node
struct TreeNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = newTreeNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* current = dequeue(q);
        if (!current) continue;

        // Left child
        current->left = newTreeNode(arr[i++]);
        if (current->left) enqueue(q, current->left);

        // Right child
        if (i < n) {
            current->right = newTreeNode(arr[i++]);
            if (current->right) enqueue(q, current->right);
        }
    }

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, N);
    inorder(root);
    printf("\n");
    return 0;
}