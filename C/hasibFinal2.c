#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int front=-1;   int rear=-1;
int queue[MAX];

void enqueue(int num)
{
    if(rear==MAX-1)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("Last pushed element is %d\n",num);
        rear=rear+1;
        queue[rear]=num;
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        printf("Last deleted element is %d\n",queue[front]);
        front++;
    }
}

void display()
{
    if(rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
}