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

void enqueue(void);
int dequeue(void);
void display(void);

int main ()
{
    int choice;
    int option = 1;
    q.front = -1;
    q.rear = -1;

    printf ("QUEUE OPERATION\n");
    while (option)
    {
        printf ("      1    -->    ENQUEUE               \n");
        printf ("      2    -->    DEQUEUE               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT                  \n");

        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
    return 0;
}

// Question a: Enqueue
void enqueue ()
{
    int num;
    if (q.rear == (MAXSIZE - 1))
    {
        printf ("Queue is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be enqueued\n");
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

// Question b: Dequeue
int dequeue ()
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
        printf ("dequeued element is = %d\n", q.que[q.front]);
        q.front = q.front + 1;

        if (q.front > q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
    }
    return(num);
}

// Question c: Display
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