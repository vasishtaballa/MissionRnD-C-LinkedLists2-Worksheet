/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *current1 = head1, *current2 = head2, *temp = NULL, *ans = NULL;
	while (current2 != NULL)
	{
		if (current1 == NULL || current2 == NULL)
			break;
		if ((current1->num) > (current2->num))
		{
			if (temp == NULL)
			{
				temp = (struct node *)malloc(sizeof(node));
				ans = temp;
				temp->num = current2->num;
				temp->next = NULL;
				current2 = current2->next;
			}
			else
			{
				temp->next = current2;
				temp = temp->next;
				current2 = current2->next;
			}
		}
		else
		{
			if (temp == NULL)
			{
				temp = (struct node *)malloc(sizeof(node));
				ans = temp;
				temp->num = current1->num;
				temp->next = NULL;
				current1 = current1->next;
			}
			else
			{
				temp->next = current1;
				temp = temp->next;
				current1 = current1->next;
			}
		}
	}
	if (current1 == NULL)
		temp->next = current2;
	if (current2 == NULL)
		temp->next = current1;
	return ans;
}
