#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct queue
{
    int data;
    struct queue *next;
}queue;


void push(queue **front, queue **rear, int data) 
{
    queue *node = (queue*)malloc(sizeof(queue));

    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
        if (*front == NULL)
        {
            //this is the first node
            *front = *rear = node;
        }

        else
        {
            //this is not the first node, so append it..
            (*rear)->next = node;
            *rear = node;
        }
    }
}


void pop(queue **front, queue **rear) 
{
    if(*front != NULL) 
    {
        queue *remove = *front;
        *front = (*front)->next;
        
        //if this is the only availabe node in the queue 
        //then we must set the rear also to NULL
        if(remove->next == NULL) *rear = NULL;

        free(remove);
    }

}

void display(queue *front)
{
    if(front != NULL)
    {
        printf("[");
        while (front->next != NULL)
        {
            printf("%d, ", front->data);
            front = front->next;
        }
        printf("%d]\n", front->data);
    }

}

int main()
{
    queue *front, *rear;
    front = rear = NULL;
    int data, choice;
    while (true)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            push(&front, &rear, data);
            break;

        case 2:
            pop(&front, &rear);
            break;

        case 3:
            printf("Queue : ");
            display(front);
            break;

        case 4:
            exit(0);

        default:
            printf("Enter valid choice\n");
            //in case if user input the string then
            // we must flush the buffer to get out of the infinite loop....
            fflush(stdin);
        }
    }
    return 0; 
}