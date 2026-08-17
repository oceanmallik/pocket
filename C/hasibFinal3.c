#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
    int data[5];
    int prior[5];
    int n=0;

    data[n]=10;
    prior[n]=2;
    n++;

    data[n]=20;
    prior[n]=1;
    n++;

    data[n]=50;
    prior[n]=4;
    n++;

    data[n]=40;
    prior[n]=3;
    n++;
    //queue
    for(int i=0;i<n;i++)
    {
        printf("data = %d , priority = %d \n",data[i],prior[i]);
    }

    //sorting
    printf("\n\nAfter Sorting \n");



   for(int i = 0; i < n - 1; i++)
{
    for(int j = 0; j < n - i - 1; j++)
    {
        if(prior[j] < prior[j + 1])
        {
            int temp = prior[j];
            prior[j] = prior[j + 1];
            prior[j + 1] = temp;

            temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
        }
    }
}


    for(int i=0;i<n;i++)
    {

        printf("data = %d , priority = %d \n",data[i],prior[i]);
    }
    printf("\n\n");

    for(int i=0;i<n-1;i++)
    {
        data[i]=data[i+1];
        prior[i]=prior[i+1];

    }
    n--;
     for(int i=0;i<n;i++)
    {

        printf("data = %d , priority = %d \n",data[i],prior[i]);
    }


}