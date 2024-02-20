#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort
 * @list: Pointer to the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	current = (*list)->next;

	if (list == NULL || *list == NULL)
		return;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}
		current = temp;
	}
}
