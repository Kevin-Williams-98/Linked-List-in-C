#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
/*
 * Node.h
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 */

#ifndef NODE_H_
#define NODE_H_

struct Node
{
    // Any data type can be stored in this node
    char  *data;

    struct Node *next;
};
struct node* enqueue(struct node *head, char *s);
struct node* push(struct node *head, char *s);
void printlist(struct node *head);
struct node* deletelist(struct node *head);
struct node* deletenode(struct node *head, char *s);



#endif /* NODE_H_ */
