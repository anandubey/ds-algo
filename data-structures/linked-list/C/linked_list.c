/*
*   author: anandubey
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(int argc, char const *argv[])
{
    // Declare three nodes
    struct Node* head = NULL;
    struct Node* second_node = NULL;
    struct Node* third_node = NULL;

    // Allocate memory for 3 nodes in the heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second_node = (struct Node*) malloc(sizeof(struct Node));
    third_node = (struct Node*) malloc(sizeof(struct Node));

    /*
    *   Three blocks have been allocated dynamically.
    *   We have pointers to these three blocks as head,
    *   second and third    
    *       head           second           third
    *        |                |               |
    *        |                |               |
    *    +---+-----+     +----+----+     +----+----+
    *    | #  | #  |     | #  | #  |     |  # |  # |
    *    +---+-----+     +----+----+     +----+----+
    *
    *   # represents any random value.
    *   Data is random because we haven’t assigned
    *   anything yet  
    */
    
    // Assigning data to first node
    head->data = 1;
    head->next = second_node;   // The first node is pointing to second node.

    /*
    *   The structure node looks like the following after
    *   assignment of data and updating next pointer
    *   
    *       head           second           third
    *        |                |               |
    *        |                |               |
    *    +---+-----+     +----+----+     +----+----+
    *    | 1  |  0------>| #  | #  |     |  # |  # |
    *    +---+-----+     +----+----+     +----+----+
    *
    */

    // Assigning values to second and third node in the linked list

    second_node->data = 2;
    second_node->next = third_node;

    third_node->data = 3;
    third_node->next = NULL; 

    /*
    *   The structure node looks like the following after
    *   assignment of data and updating next pointer
    *   
    *       head           second           third
    *        |                |               |
    *        |                |               |
    *    +---+-----+     +----+----+     +----+-----+
    *    | 1  |  0------>| 2  |  0------>| 3 | NULL |
    *    +---+-----+     +----+----+     +----+-----+
    *
    */

    print_list(second_node);
    return 0;
}
