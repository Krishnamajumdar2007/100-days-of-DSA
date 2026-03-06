#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    int x;
    struct node *temp;
    
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    
    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);
    
    return x;
}

int main()
{
    char exp[100];
    int i = 0, a, b, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}