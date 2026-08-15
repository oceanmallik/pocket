#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

// Question a: (at the end of the code)
// Question b: Traverse a linked list
void printLL(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

// Question c: Insert at begin
struct node *insertAtBegin(struct node *head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = head;
    return newNode;
}

// Question d: Insert at end
struct node *insertAtEnd(struct node *head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp = head;

    newNode->value = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Question e: Delete at begin
struct node *deleteAtBegin(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    head = head->next;
    free(temp);
    return head;
}

// Question f: Delete at end
struct node *deleteAtEnd(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

int main()
{
// Question a: Create a linked list
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->value = 10;
    two->value = 20;
    three->value = 30;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    printf("Created and Traversed: ");
    printLL(head);
    printf("Insert at begin: ");
    head = insertAtBegin(head, 5);
    printLL(head);
    printf("Insert at end: ");
    head = insertAtEnd(head, 40);
    printLL(head);
    printf("Delete at begin: ");
    head = deleteAtBegin(head);
    printLL(head);
    printf("Delete at end: ");
    head = deleteAtEnd(head);
    printLL(head);

    return 0;
}