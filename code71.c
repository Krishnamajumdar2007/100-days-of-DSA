#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        return;
    }

    struct Node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        return;
    }

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    // Input number of elements
    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Perform dequeue m times
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display final queue
    display();

    return 0;
}