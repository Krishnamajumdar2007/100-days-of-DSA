#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node *p1 = head1, *p2 = head2;

    while (p1 != p2) {
        if (p1 == NULL)
            p1 = head2;
        else
            p1 = p1->next;

        if (p2 == NULL)
            p2 = head1;
        else
            p2 = p2->next;
    }
    return p1;
}

int main() {
    int n, m, i, val;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *last = NULL;

    scanf("%d", &n);

    struct Node* nodes[100];  
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = createNode(val);
        nodes[i] = temp;

        if (head1 == NULL)
            head1 = temp;
        else
            last->next = temp;

        last = temp;
    }

    scanf("%d", &m);
    last = NULL;

    for (i = 0; i < m; i++) {
        scanf("%d", &val);

        struct Node* match = NULL;

        for (int j = 0; j < n; j++) {
            if (nodes[j]->data == val) {
                match = nodes[j];
                break;
            }
        }

        if (match != NULL) {
            if (head2 == NULL)
                head2 = match;
            else
                last->next = match;
            break;  
        } else {
            temp = createNode(val);

            if (head2 == NULL)
                head2 = temp;
            else
                last->next = temp;

            last = temp;
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}