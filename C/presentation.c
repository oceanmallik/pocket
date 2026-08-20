#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int flag;
    struct Node *next;
};

int main()
{
    // Nodes creation
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *ptr = NULL;

    // Allocation memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assigning data and flags
    head->data = 10;
    head->flag = 1;

    second->data = 20;
    second->flag = 0;

    third->data = 30;
    third->flag = 0;

    // Making a circle
    head->next = second;
    second->next = third;
    third->next = head;

    printf("Before Deletion:\n");
    ptr = head;
    do
    {
        printf("Data: %d, Flag: %d\n", ptr->data, ptr->flag);
        ptr = ptr->next;
    } while (ptr != head);

    // Deleting the head node
    ptr = head;
    head = second;
    third->next = head;
    head->flag = 1;
    free(ptr);

    printf("\nAfter Deletion:\n");
    ptr = head;
    do
    {
        printf("Data: %d, Flag: %d\n", ptr->data, ptr->flag);
        ptr = ptr->next;
    } while (ptr != head);
}