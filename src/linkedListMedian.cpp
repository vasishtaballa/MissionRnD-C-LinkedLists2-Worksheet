/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head == NULL)
		return -1;
	int median = 0;
	struct node *current = head, *temp = head;
	while (current != NULL)
	{
		if (current->next != NULL && current->next->next == NULL)
		{
			median = ((temp->num) + (temp->next->num)) / 2;
			break;
		}
		else if (current->next != NULL)
		{
			current = current->next->next;
			temp = temp->next;
		}
		else if (current->next == NULL)
		{
			median = temp->num;
			break;
		}
	}
	return median;
}

