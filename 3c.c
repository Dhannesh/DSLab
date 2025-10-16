#define SIZE 10
#include <stdio.h>

struct DeQue
{
    int data[SIZE];
    int front, rear;
} DQ;

int isEmpty()
{
    return DQ.front == -1;
}
int isFUll()
{
    return (DQ.rear + 1) % SIZE == DQ.front;
}

void enqueueFront(int info)
{
    if (isFUll())
    {
        printf("DeQue is full\n");
        return;
    }
    if (DQ.front == -1)
        DQ.front = DQ.rear = 0;
    else
        DQ.front = (DQ.front - 1 + SIZE) % SIZE;
    DQ.data[DQ.front] = info;
}
void enqueueRear(int info)
{
    if (isFUll())
    {
        printf("DeQue is full\n");
        return;
    }
    if (DQ.front == -1)
        DQ.front = DQ.rear = 0;
    else
        DQ.rear = (DQ.rear + 1) % SIZE;
    DQ.data[DQ.rear] = info;
}
int dequeueFront()
{
    int item;
    if (isEmpty())
    {
        printf("\nDeQue is empty\n");
        return -1;
    }
    item = DQ.data[DQ.front];
    if (DQ.front == DQ.rear)
        DQ.front = DQ.rear = -1;
    else
        DQ.front = (DQ.front + 1) % SIZE;
    return item;
}
int dequeueRear()
{
    int item;
    if (isEmpty())
    {
        printf("\nDeQue is empty\n");
        return -1;
    }
    item = DQ.data[DQ.rear];
    if (DQ.front == DQ.rear)
        DQ.front = DQ.rear = -1;
    else
        DQ.rear = (DQ.rear - 1 + SIZE) % SIZE;
    return item;
}
void traverse()
{
    if (isEmpty())
    {
        printf("CQueue is Empty\n");
        return;
    }
    printf("front=%d, rear=%d\n", DQ.front, DQ.rear);
    int i = DQ.front;
    while (i != DQ.rear)
    {
        printf("%d ", DQ.data[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d ", DQ.data[i]);
    printf("\n");
}
int main()
{
    DQ.front = DQ.rear = -1;
    int ch, info;
    do
    {
        printf("\n1.........Enqueue Front"
               "\n2.........Enqueue Rear"
               "\n3.........Dequeue Front"
               "\n4.........Dequeue Rear"
               "\n5.........Traverse"
               "\n6.........IsEmpty"
               "\n7.........IsFull"
               "\n8.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            enqueueFront(info);
            break;
        case 2:
            printf("Enter info: ");
            scanf("%d", &info);
            enqueueRear(info);
            break;
        case 3:
            info = dequeueFront();
            if (info != -1)
                printf("Removed Element: %d", info);
            break;
        case 4:
            info = dequeueRear();
            if (info != -1)
                printf("Removed Element: %d", info);
            break;
        case 5:
            traverse();
            break;
        case 6:
            printf("The Double Ended Queue is %s\n", (isEmpty() ? "Empty" : "Not Empty"));
            break;
        case 7:
            printf("The Double Ended Queue is %s\n", (isFUll() ? "Full" : "Not Full"));
            break;
        case 8:
            printf("\nThis code is executed by Mr. XYZ with Roll No XXXXXX\n");
            break;
        default:
            printf("Invalid Choice! Try again\n");
        }
    } while (ch != 8);
}
