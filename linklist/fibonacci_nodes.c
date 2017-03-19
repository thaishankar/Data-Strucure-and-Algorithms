// C program to reverse a linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void MoveNode(struct node **dest, struct node **src) {
	struct node *newnode = *src;
	*src = newnode->next;
	newnode->next = *dest;
	*dest = newnode;
}

void fibonacci (struct node *head, int curr, int next) {
	if (!head) return;
	if (curr == next) {
		printf (" %d ", node->data);
		next = next + curr - 1;
	}

	fibonacci (head, curr+1, next);
	

}
 
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\nGiven linked list \n");
     printList(head);
     odd_even(&head);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}
