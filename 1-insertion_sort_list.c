#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	in ascending order
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		node = curr->next;
		tmp = curr->prev;

		while (tmp != NULL && tmp->n > curr->n)
		{
			swap(list, &tmp, curr);
			print_list((const listint_t *)*list);
		}
		curr = node;
	}
}


/**
 * swap - Swaps two nodes in a doubly-linked list
 * @h: pointer to start node
 * @n1: pointer to first node
 * @n2: pointer to second node
 */
void swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->next = *n1;
	n2->prev = (*n1)->prev;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
