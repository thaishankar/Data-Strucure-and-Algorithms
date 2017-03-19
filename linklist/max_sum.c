// C++ program to construct the maximum sum linked
// list out of two given sorted lists
#include<iostream>
using namespace std;
 
//A linked list node
struct Node
{
    int data; //data belong to that node
    Node *next; //next pointer
};
 
// Push the data to the head of the linked list
void push(Node **head, int data)
{
    //Alocation memory to the new node
    Node *newnode = new Node;
 
    //Assigning data to the new node
    newnode->data = data;
 
    //Adjusting next pointer of the new node
    newnode->next = *head;
 
    //New node becomes the head of the list
    *head = newnode;
}
 
// Method that adjusts the pointers and prints the final list
void finalMaxSumList(Node *a, Node *b)
{
    Node dummy;
    dummy.next = NULL;
    Node *result = &dummy;
    int sumA = 0, sumB = 0;
    Node *startA = a, *startB = b;
    Node *currA = a, *currB = b;

    while ( currA && currB) {
	if(currA->data == currB->data) {

		while(result->next && (result->next != currA && result->next != currB)) {
			result = result->next;
		}

		if(sumA > sumB)
			result->next = startA;
		else
			result->next = startB;
		currA = currA->next;
		currB = currB->next;
		startA = currA;
		startB = currB;
		sumA = 0;
		sumB = 0;
        }
	else if(currA->data < currB->data) {
		sumA += currA->data;
		currA = currA->next;
	}
	else {
		sumB += currB->data;
		currB = currB->next;
	}

    }

   if(currA)
	result->next = a;
   if(currB)
	result->next = b;
 

    result = dummy.next;

    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
}
 
//Main driver program
int main()
{
    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    Node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);
 
    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);
 
    finalMaxSumList(head1, head2);
    return 0;
}
