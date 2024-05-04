#include "sort.h"


/**
* insertion_sort_list - insertion sorting algorithm
* @list: linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;
	int value;

	if (!list || !*list)
		return;

	current = *list;
	while (current)
	{
		temp = current->next;
		prev = current;
		while (temp)
		{
			if (current->n > temp->n)
			{
				value = temp->n;
				*(int *)&temp->n = current->n;
				*(int *)&current->n = value;
				if (current == *list)
					*list = temp;
				else
					prev->next = temp;
				prev = current;
				current = temp->next;
				temp = current;

				print_list(*list);
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
		}
		current = current->next;
	}
}
