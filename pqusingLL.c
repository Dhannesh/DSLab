#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int info, py;
    struct Node *next;
} *front;

struct Node *getNode(int info, int py)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->py = py;
    temp->next = NULL;
    return temp;
}

void enqueue(int info, int py)
{
    struct Node *newNode = getNode(info, py);
    if (front == NULL || front->py < py)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {

        struct Node *current = front;
        while (current->next != NULL && current->next->py >= py)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty");
        return -1;
    }
    int data = front->info;
    front = front->next;
    return data;
}
void traverse()
{
    if (front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d %d| ", temp->info, temp->py);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    front = NULL;
    int ch, info, py;
    do
    {
        printf("\n1.........Enqueue"
               "\n2.........Dequeue"
               "\n3.........Traverse"
               "\n4.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter info and priority: ");
            scanf("%d %d", &info, &py);
            enqueue(info, py);
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
            printf("\nThis code is executed by Mr. XYZ with Roll No XXXXXX\n");
            break;
        default:
            printf("Invalid Choice! Try again\n");
        }
    } while (ch != 4);
}