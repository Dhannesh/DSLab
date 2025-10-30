#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next, *prev;
} *front, *rear;
struct Node *getNode(int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
int isEmpty()
{
    return front == NULL;
}

void enqueueFront(int info)
{
    struct Node *temp = getNode(info);

    if (front == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}
void enqueueRear(int info)
{
    
}
void dequeueFront()
{
}
int dequeueRear()
{
}

int main()
{
    front = rear = NULL;
}