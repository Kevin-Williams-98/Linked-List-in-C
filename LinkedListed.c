#include"Node.h"
#include "projHeader.h"
/*
 * LinkedListed.c
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 */

struct node* enqueue(struct node *head, char *s)
{
	struct node *new = malloc(sizeof(struct node));
	new->data = strdup(s);
	new->next = NULL;
	//printf("This is new %s\n", new->data);
	if(head == NULL)
	{
		head = new;
		//printf("This is head %s\n", head->data);
		return head;
	}

	struct node *temp = head;
	//printf("This is temp %s\n", temp->data);
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	return head;
}

struct node* push(struct node *head, char *s)
{
	struct node *new = malloc(sizeof(struct node));
	new->data = strdup(s);
	new->next = NULL;
	if(head == NULL)
		head = new;
	else
	{
		new->next = head;
		head = new;
	}
	return head;
}

void printlist(struct node *head)
{
	if(head == NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		struct node *temp = head;
		while(temp != NULL)
		{
			printf("%s\n", temp->data);
			temp = temp->next;
		}
	}
}

struct node* deletelist(struct node *head)
{
	struct node *temp = head;
	while(head != NULL)
	{
		head = head->next;
		temp->next = NULL;
		temp->data = 0;
		free(temp);
		temp = head;
	}
	head = NULL;
	return head;
}

struct node* deletenode(struct node *head, char *s)
{
	struct node *temp = head;
	if(s != NULL)
	{
		if(mystrcmp(head->data, s))
		{
			head = head->next;
			temp->next = NULL;
			temp->data = 0;
			free(temp);

		}
		else{
			while(!(mystrcmp(temp->next->data, s)) && temp->next != NULL)
				temp = temp->next;

			struct node *nodetodelete = temp->next;
			temp->next = temp->next->next;
			nodetodelete->next = NULL;
			nodetodelete->data = 0;
			free(nodetodelete);
		}
	}

	return head;
}





