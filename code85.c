#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue with front and rear pointers
struct Node *front = NULL, *rear = NULL;

// Stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to push to stack
void push(struct StackNode** top_ref, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = *top_ref;
    *top_ref = newNode;
}

// Function to pop from stack
int pop(struct StackNode** top_ref) {
    if (*top_ref == NULL) return -1;
    struct StackNode* temp = *top_ref;
    int data = temp->data;
    *top_ref = (*top_ref)->next;
    free(temp);
    return data;
}

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) return -1;

    struct Node* temp = front;
    int data = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;
    free(temp);
    return data;
}

// Function to reverse the queue using a stack
void reverseQueue() {
    struct StackNode* stack = NULL;

    // Push all elements of the queue onto the stack
    while (front != NULL) {
        push(&stack, dequeue());
    }

    // Pop elements from stack and enqueue back into queue
    while (stack != NULL) {
        enqueue(pop(&stack));
    }
}

// Function to print the queue
void printQueue() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();
    printQueue();

    return 0;
}