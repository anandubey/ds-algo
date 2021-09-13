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
