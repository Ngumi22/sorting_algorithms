#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr->next;
		swap = curr->prev;
		while (swap && swap->n > curr->n)
		{
			if (swap->prev)
				swap->prev->next = curr;
			else
				*list = curr;
			if (curr->next)
				curr->next->prev = swap;
			swap->next = curr->next;
			curr->prev = swap->prev;
			curr->next = swap;
			swap->prev = curr;
			print_list((const listint_t *)*list);
			swap = curr->prev;
		}
		curr = tmp;
	}
}
