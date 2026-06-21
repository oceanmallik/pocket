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
    printf("\n");

    // Add new stuff in middle
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));
    newNode -> value = 40;

    newNode -> next = two; // newnode, two
    one -> next = newNode; // one, newnode
    // one, newnode, two

    printLL(head);
    printf("\n");

    // Add new stuff at start
    struct node *newHead = NULL;
    newHead = malloc(sizeof(struct node));
    newHead -> value = 0;

    newHead -> next = head;
    head = newHead;

    printLL(head);
    printf("\n");
}