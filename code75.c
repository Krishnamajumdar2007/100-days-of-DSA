#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Initialize
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Check empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// Size
int getSize(Deque* dq) {
    return dq->size;
}

// push_front
void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// push_back
void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// pop_front
void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

// pop_back
void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

// front
int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->front->data;
}

// back
int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->rear->data;
}

// clear
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// reverse
void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        dq->front = temp->prev;

    // swap front and rear
    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}

// display
void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// swap two deques
void swapDeque(Deque* a, Deque* b) {
    Deque temp = *a;
    *a = *b;
    *b = temp;
}

// sort (simple bubble sort)
void sortDeque(Deque* dq) {
    if (empty(dq)) return;

    Node* i;
    Node* j;

    for (i = dq->front; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 5);
    push_back(dq, 20);
    push_front(dq, 1);

    display(dq);   // 1 5 10 20

    printf("Front: %d\n", front(dq)); // 1
    printf("Back: %d\n", back(dq));   // 20

    pop_front(dq);
    pop_back(dq);

    display(dq);   // 5 10

    sortDeque(dq);
    display(dq);   // 5 10

    reverse(dq);
    display(dq);   // 10 5

    printf("Size: %d\n", getSize(dq));

    clear(dq);
    printf("Empty: %d\n", empty(dq));

    return 0;
}