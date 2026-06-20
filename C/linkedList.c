#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

void printLL (struct node *p) {
    while (p != NULL)
    {
        printf("%d ", p-> value);
        p = p -> next;
    }
}

int main()
{
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one -> value = 10;
    two -> value = 20;
    three -> value = 30;

    one -> next = two;
    two -> next = three;
    three -> next = NULL;

    head = one;
    printLL(head);
}