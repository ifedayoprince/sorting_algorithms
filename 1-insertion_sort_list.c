#include "sort.h"


/**
* insertion_sort_list - insertion sorting algorithm
* @list: linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int value;

	if (!list)
		return;

	current = *list;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->n > temp->n)
			{
				value = current->n;
				current->n = temp->n;
				temp->n = value;
				current = *list;

				print_list(*list);
				break;
			}
			temp = temp->next;
		}
		current = current->next;
	}
}
