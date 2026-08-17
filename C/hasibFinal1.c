#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int top=-1;

int stack[MAX];

void push(int num)
{
    if(top==MAX-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        stack[++top]=num;
        printf("The last pushed element is %d\n",num);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is underlfow\n");

    }
    else
    {
        printf("Last popped element is %d\n",stack[top]);
        top=top-1;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    pop();
    display();
}