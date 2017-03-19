// C program to reverse a linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Reverses the linked list in groups of size k and returns the 
   pointer to the new head node. */
struct node * pairwise (struct node *head)
{
    struct node *next, *curr, *prev = head;
 
    if (head == NULL)
	return NULL;

    if (head->next == NULL)
	return head;

    curr = prev->next;

    
    next = curr->next;

    curr->next = prev;
    prev->next = pairwise(next); 

    return curr;
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
     head = pairwise(head);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}
