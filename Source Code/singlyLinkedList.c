#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}nodetype;


void insert(nodetype **head, nodetype **tail, int data) {
	nodetype *node = (nodetype*)malloc(sizeof(nodetype));
	if(node != NULL) {
		node->data = data;
		node->next = NULL;
		if(*head == NULL) {
			//this is the first node
			*head = *tail = node;
		}

		else {
			//this is not the first node, so append it..
			(*tail)->next = node;
			*tail = node;
		}

	}
}

void display(nodetype *head) {
	printf("List : ");
	while(head != NULL) {
	    printf("%d ",head->data);
	    head = head->next;
	}
	printf("\n");
}


int main()
{
	int data, choice;
	nodetype *head, *tail;
	head = tail = NULL;
	while(true) {
		printf("\n");
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
					printf("Enter data : ");
					scanf("%d", &data);
					insert(&head, &tail, data);
					break;

			case 2:
					display(head);
					break;

			case 3:
					exit(0);

			default:
					printf("Enter valid choice\n");
		}
	}
	return 0;
}