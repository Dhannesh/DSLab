#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
} *front, *rear;

struct Node *getNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    return temp;
}
int isEmpty()
{
    return front == NULL;
}
void traverse()
{
    if (front == NULL)
    {
        printf("Empty Queue");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int info)
{
    struct Node *newNode = getNode(info);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    int info;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    info = front->info;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    return info;
}

int main()
{
    front = rear = NULL;
    int ch, info;
    do
    {
        printf("\n1.........Enqueue"
               "\n2.........Dequeue"
               "\n3.........Traverse"
               "\n4.........IsEmpty"
               "\n5.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            enqueue(info);
            break;
        case 2:
            info = dequeue();
            if (info != -1)
                printf("Removed Element: %d", info);
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("The queue is %s\n", (isEmpty() ? "Empty" : "Not Empty"));
            break;
        case 5:
            printf("\nThis code is executed by Mr. XYZ with Roll No XXXXXX\n");
            break;
        default:
            printf("Invalid Choice! Try again\n");
        }
    } while (ch != 5);
}