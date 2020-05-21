#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst 
{
    int data;
    struct bst *left;
    struct bst *right;
}bst_node;

bst_node* create_node(int data) 
{
    bst_node *node = (bst_node*)malloc(sizeof(bst_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void inorder(bst_node *root) 
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void insert(bst_node **root, int data) 
{
    if(*root == NULL) 
    {
        *root = create_node(data);
        return;
    }

    else if(data < (*root)->data)
        insert(&(*root)->left, data);

    else
        insert(&(*root)->right, data);
}

bst_node* search(bst_node *root, int data) {
    if(root == NULL) return NULL;
    else if(data == root->data) return root;
    else if(data < root->data) return search(root->left, data);
    else if(data > root->data) return search(root->right, data);
}


bst_node* findmin(bst_node *root) {
	if(root == NULL) {
	       	return root;
		printf("Tree is empty");
	}
	else if(root->left == NULL) return root;
	else return findmin(root->left);
}


bst_node*  delete(bst_node *root, int data) {
	if(root == NULL);
	else if(data < root->data)
	       	root->left = delete(root->left, data);
	else if(data > root->data)
		root->right = delete(root->right, data);
	else {
		// case 1 : if left and right both are null
		if(root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}

		//case 2 : if left child is null
		else if(root->left == NULL) {
			bst_node *temp = root->right;
			free(root);
			root = temp;
		}

		//case 3 : if right child is null
		else if(root->right == NULL) {
			bst_node *temp = root->left;
			free(root);
			root = temp;
		}


		//case 4 : if both left and right child is not null
		else {
              bst_node *temp = findmin(root->right);
		      root->data = temp->data;
		      root->right = delete(root->right, temp->data);
		}
	}
	return root;
}

int main() 
{
    bst_node *root, node;
    root = NULL;
    int data, choice;
    while (true)
    {
        printf("\n");
        printf("1. insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
	    printf("5. Minimum\n");
	    printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            insert(&root, data);
            break;

        case 2:
            printf("Bst : ");
            inorder(root);
            break;

        case 3:
            printf("Enter data : ");
            scanf("%d", &data);
            bst_node *node = search(root, data);
            if(node != NULL) printf("Found it\n");
            else printf("Can't found\n");
            break;

	case 4:
	    	printf("Enter data : ");
		scanf("%d", &data);
	    	root = delete(root, data);
		break;
	
	case 5:
		node = findmin(root);
		printf("Minimum Value is : %d\n", node->data);
		break;

        case 6:
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
