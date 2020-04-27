#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
}stack;

void push(stack **top, int data) {
    stack *node = (stack*)malloc(sizeof(stack));
    if(node != NULL) {
        node->data = data;
        node->next = *top;
        *top = node;
    }
}

void pop(stack **top) {
    if(*top == NULL);

    else {
        stack *remove = *top;
        *top = (*top)->next;
        free(remove);
    }
}

void display(stack *top) {
    if(top == NULL);

    else {
        printf("[");
        while (top->next != NULL) {
            printf("%d, ", top->data);
            top = top->next;
        }
        printf("%d]\n", top->data);
    }
}


int main() {
    stack *top = NULL;
    int data, choice;
    while (true) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("4. Pop\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            printf("Stack : ");
            display(top);
            break;

        case 3:
            exit(0);

        case 4:
            pop(&top);
            break;

        default:
            printf("Enter valid choice\n");
            //in case if user input the string then
            // we must flush the buffer to get out of the infinite loop....
            fflush(stdin);
        }
    }
    return 0;
}