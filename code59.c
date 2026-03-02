#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        scanf("%d", &newNode->exp);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   
            temp = head;
        } else {
            temp->next = newNode; 
            temp = newNode;       
        }
    }
    temp = head;
    while(temp != NULL) {
        printf("%dx^%d ", temp->data,temp->exp);
        temp = temp->next;
    }

    return 0;
}