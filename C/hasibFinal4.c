#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked List is already empty\n");

    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp1=head;
        struct node *temp2=head;

        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
        temp1=NULL;
    }
    return head;
};

struct node* add_at_begin(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head=temp;

    return temp;
};

struct node* add_at_end(struct node *head,int data)
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
};


struct node* delete_at_begin(struct  node *head)
{
    if(head==NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {


        struct node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
};


int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;


    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=20;
    temp1->next=NULL;

    struct node *temp2=(struct node*)malloc(sizeof(struct node));
    temp2->data=30;
    temp2->next=NULL;

    head->next=temp1;
    temp1->next=temp2;
    head=add_at_begin(head,100);

    head=delete_at_begin(head);
    temp2=head;
    head=add_at_end(head,200);
    head=delete_at_end(head);
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
}