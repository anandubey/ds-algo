/******************************************************************************
*   author: Anand Kumar Dubey
*   TODO:
*       1. Write delete node function recursively
******************************************************************************/


/**********************************  NOTE  ************************************
 * 
 *       1. Always pass head argument by reference if the function might modify
 *           the head pointer.
 *       ref: https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/
 * 
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


/*************************** Function declarations ***************************/

// Add a node at the beginning of the linked list 
void push_node(struct Node** node_ref, int data);

// Add a node at the end of the linked list
void append_node(struct Node** node_ref, int data);

// Add a node after a given node
void insert_after(struct Node* node, int data);

// Deleting node based on position (with pos being indexed based 1)
void delete_node(struct Node** node_ref, int pos);

// Get length of the linked list
int get_length(struct Node* node);

/*********************** Function declarations END ***************************/


void push_node(struct Node** head_ref, int new_data)
{
    // Create new node and add data & next pointer
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;

    // Move the head to point to the new node
    *head_ref = new_node;
}


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


void insert_after(struct Node* node, int new_data)
{
    if (node == NULL)
    {
        return;
    }

    // Create new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = node->next;
    node->next = new_node; 
}



void delete_node(struct Node** head_ref, int pos)
{
    struct Node *node = (*head_ref), *prev_node=NULL;

    // If Linked list is empty
    if(node == NULL || pos < 1)
    {
        return;
    }

    // If head needs to be removed
    if(pos == 1 && node->next != NULL)
    {
        *head_ref = (*head_ref)->next;
        free(node);
        return;
    }

    // For all other case of deletion
    while(pos-- > 1 )
    {
        if(node != NULL)
        {
            prev_node = node;
            node = node->next;
            //printf("\n %d %d ", prev_node->data, node->data);

        }
    }

    if(node == NULL)
    {
        return;
    }

    prev_node->next = node->next;
    free(node);
}


int get_length(struct Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + get_length(head->next);
}


int main()
{
    struct Node* head = NULL;

    // Insert 1. Linked list becomes: 1 -> NULL
    append_node(&head, 1);

    // Insert 2. Linked list becomes: 2 -> 1 -> NULL
    push_node(&head, 2);

    // Insert 3. Linked list becomes: 3 -> 2 -> 1 -> NULL
    push_node(&head, 3);

    // Insert 8. Linked list becomes: 3 -> 2 -> 8 -> 1 -> NULL
    insert_after(head->next, 8);

    printf("\nThe following linked list is created: ");
    print_linked_list(head);

    int len = get_length(head);
    printf("\n %d ", len);

    delete_node(&head, 3);

    printf("\nAfter deleting a node: ");
    print_linked_list(head);

    return 0;
}
