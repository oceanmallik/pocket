#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("enqueue %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("empty\n");
    } else {
        printf("dequeue %d\n", queue[front]);
        front++;
        if (front > rear) { // Reset queue if it becomes empty
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("display %d\n", queue[i]);
        }
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    return 0;
}
