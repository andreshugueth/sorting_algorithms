#include "sort.h"


/**
 * swap - Redirecting the pointers of two nodes
 *
 * @list: Linked list
 * @current: Current node to swap (src)
 * @next: Destination node
 *
 * Return: Left node of the actual node
 */
listint_t *swap(listint_t **list, listint_t *current, listint_t *next)
{
	listint_t *left, *right;

	left = current->prev, right = next->next;

	next->next = current;
	next->prev = left;

	current->next = right;
	current->prev = next;

	if (left)
		left->next = next;
	else
		*list = next;

	if (right)
		right->prev = current;

	return (left);
}


/**
 * insertion_sort_list - sort one item at a time
 * @list: double linked list
 *
 * Return: Nothing
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *left, *tmp;

	if (!list || !*list)
		return;

	for (current = *list; current; current = next)
	{
		next = current->next;

		if (!next)
			break;

		if (next && current->n <= next->n)
			continue;

		left = swap(list, current, next);
		print_list(*list);

		tmp = next;
		while (left && tmp && left->n > tmp->n)
		{
			left = swap(list, left, tmp);
			print_list(*list);
			tmp = left ? left->next : NULL;
		}
	}

}
