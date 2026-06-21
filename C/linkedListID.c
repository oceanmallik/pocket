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
// Insert and Delete
int main()
{
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;
    struct node *five = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));
    five = malloc(sizeof(struct node));

    one -> value = 10;
    two -> value = 20;
    three -> value = 30;
    four -> value = 40;
    five -> value = 50;

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;

    head = one;

    printLL(head);
    printf("\n");

    // Delete from head and removing one
    head = two;
    free(one);
    // two, three, four, five

    printLL(head);
    printf("\n");

    // Adding one again
    one -> value = 10;
    head = one;
    one -> next = two;
    // one, two, three, four, five

    printLL(head);
    printf("\n");

    // Deleting from end
    four -> next = NULL;
    free(five);
    // one, two, three, four

    printLL(head);
    printf("\n");

    // Adding five again
    five -> value = 50;
    four -> next = five;
    five -> next = NULL;
    // one, two, three, four, five

    printLL(head);
    printf("\n");

    // Deleting from middle (three)
    two -> next = four;
    free(three);

    printLL(head);
    printf("\n");

    // Adding three again
    three -> value = 30;
    two -> next = three;
    three -> next = four;

    printLL(head);
    printf("\n");
    
}