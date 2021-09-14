#ifndef _LINKED_LIST
#define _LINKED_LIST

// A node in linked list data structure
struct Node
{
    int data;
    struct Node* next;
};

/************************** FUNCTION DECLARATIONS ****************************/

/* Print the list from given node to the last node */
void print_list(struct Node* node);

// Add a node at the beginning of the linked list 
void push_node(struct Node** node_ref, int data);

// Add a node at the end of the linked list
void append_node(struct Node** node_ref, int data);

// Add a node after a given node
void insert_after(struct Node* node, int data);

// Deleting node based on position (with pos being indexed based 1)
void delete_node(struct Node** node_ref, int pos);

/*********************** FUNCTION DECLARATIONS END ***************************/


void print_list(struct Node* node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    putchar('\n');
}

#endif
