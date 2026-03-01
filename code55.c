#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    last->next = head;

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}