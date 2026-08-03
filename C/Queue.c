#include <stdio.h>
#define MAXSIZE 5

struct queue
{
    int que[MAXSIZE];
    int front;
    int rear;
};
typedef struct queue QUEUE;
QUEUE q;

void insert(void);
int  delete_val(void);
void display(void);

void main ()
{
    int choice;
    int option = 1;
    q.front = -1;
    q.rear = -1;

    printf ("QUEUE OPERATION\n");
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    INSERT               \n");
        printf ("      2    -->    DELETE               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_val();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
}

void insert ()
{
    int num;
    if (q.rear == (MAXSIZE - 1))
    {
        printf ("Queue is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be inserted\n");
        scanf ("%d", &num);

        if (q.front == -1)
        {
            q.front = 0;
        }

        q.rear = q.rear + 1;
        q.que[q.rear] = num;
    }
    return;
}

int delete_val ()
{
    int num;
    if (q.front == -1 || q.front > q.rear)
    {
        printf ("Queue is Empty\n");
        return -1;
    }
    else
    {
        num = q.que[q.front];
        printf ("deleted element is = %d\n", q.que[q.front]);
        q.front = q.front + 1;

        if (q.front > q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
    }
    return(num);
}

void display ()
{
    int i;
    if (q.front == -1 || q.front > q.rear)
    {
        printf ("Queue is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the queue is \n");
        for (i = q.front; i <= q.rear; i++)
        {
            printf ("%d\n", q.que[i]);
        }
    }
    printf ("\n");
}
