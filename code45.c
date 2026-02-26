#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp, *newNode;
    struct Node *merged = NULL, *tail = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head1 == NULL)
            head1 = newNode;
        else {
            temp = head1;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head2 == NULL)
            head2 = newNode;
        else {
            temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (merged == NULL) {
                merged = head1;
                tail = head1;
            } else {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        } else {
            if (merged == NULL) {
                merged = head2;
                tail = head2;
            } else {
                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }
    }
    if (head1 != NULL)
        tail->next = head1;
    if (head2 != NULL)
        tail->next = head2;

    temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}