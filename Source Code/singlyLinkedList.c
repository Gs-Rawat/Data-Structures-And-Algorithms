#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}nodetype;


void push_back(nodetype **head, nodetype **tail, int data) {
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


void pop_back(nodetype **head, nodetype **tail) {
	nodetype *temp = *head;

	//if list is empty simply return...
	if(*head == NULL);

	else if(temp->next == NULL) {
		//this is the only availabe node in the linked list...
		*head = *tail = NULL;
		free(temp);
	}

	else {
		// traverse the list and head over to the second last node...
		while(temp->next != *tail) {
			temp = temp->next;
		}
		nodetype *remove_node = *tail;
		temp->next = NULL;
		*tail = temp;
		free(remove_node);
	}
}


void display(nodetype *head) {
	//if list is empty simply return;
	if(head == NULL);

	//traverse the list and print the element...
	else {
		printf("[");
		while(head->next != NULL) {
			printf("%d, ",head->data);
			head = head->next;
		}
		printf("%d]\n", head->data);
	}
}


int main()
{
	int data, choice;
	nodetype *head, *tail;
	head = tail = NULL;
	while(true) {
		printf("\n");
		printf("1. Push_Back\n");
		printf("2. Display\n");
		printf("3. Exit\n");
		printf("4. Pop_Back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
					printf("Enter data : ");
					scanf("%d", &data);
					push_back(&head, &tail, data);
					break;

			case 2:
					printf("List : ");
					display(head);
					break;

			case 3:
					exit(0);

			case 4:
					pop_back(&head, &tail);
					break;

			default:
					printf("Enter valid choice\n");
		}
	}
	return 0;
}