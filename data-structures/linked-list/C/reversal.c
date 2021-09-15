/******************************************************************************
*   author: Anand Kumar Dubey
*   TODO:
*       1. Implement reversal using recursion
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


/*************************** Function declarations ***************************/

// Add a node at the end of the linked list
void append_node(struct Node** node_ref, int data);

// Reverse the list using three pointer method - current, previous & next ptrs
void reverse_using_3_ptr(struct Node **head);

/*********************** Function declarations END ***************************/


void append_node(struct Node** head_ref, int new_data)
{
    // Create a new node and add data & give appropriate next pointer
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Else traverse to the last node in the list
    struct Node* node = *head_ref;
    while(node->next != NULL)
    {
        node = node->next;
    }
    node->next = new_node;
}


// Reverse linked list using three pointer method
void reverse_using_3_ptr(struct Node **head)
{
    struct Node *curr_node=*head, *prev_node=NULL, *next_node=NULL;

    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    *head = prev_node;
}


int main()
{
    struct Node* head = NULL;

    // Create Linked list and add data
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);
    append_node(&head, 4);
    append_node(&head, 5);
    append_node(&head, 6);

    print_linked_list(head);
    reverse_list_using_3_ptr(&head);
    print_linked_list(head);

    return 0;
}
