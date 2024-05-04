#include "sort.h"


/**
 * sort_list - Sorts a doubly linked list using
 *              the cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void sort_list(listint_t **list)
{
	listint_t *curr = *list, *start = NULL, *end = NULL;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = 0;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(curr, curr->next, list);
				swapped = 1;
			}
			else
			{
				curr = curr->next;
			}
		}
		end = curr;

		while (curr->prev != start)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(curr->prev, curr, list);
				swapped = 1;
			}
			else
			{
				curr = curr->prev;
			}
		}
		start = curr;
	} while (swapped);
}

/**
 * swap_nodes - Swaps the values of two nodes in a doubly linked list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 * @list: Pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp1 = node1->prev, *temp2 = node2->next;

	if (temp1)
		temp1->next = node2;
	else
		*list = node2;

	if (temp2)
		temp2->prev = node1;

	node1->prev = node2;
	node2->next = node1;
	node1->next = temp2;
	node2->prev = temp1;
}
