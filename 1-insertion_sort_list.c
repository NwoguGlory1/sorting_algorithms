#include "sort.h"
/**
 * swap_nodes - swaps two nodes of a doubly linked list
 * @node: Pointer to the node too be swapped
 * @list: Pointer to the head of the doubly linked list
 * Return: NIL
 */
void swap_nodes(listint_t **node, listint_t **list)
{
	listint_t *current = *node, *next_node, *prev_node;

	if (current->prev == NULL)
		*list = current->next;
	current = prev_node = *node;
	next_node = current->next;

	current->next = next_node->next;
	prev_node = current->prev;
	current->prev = next_node;
	next_node->next = current;
	next_node->prev = prev_node;

	if (next_node->prev)
		next_node->prev->next = next_node;

	if (current->next)
		current->next->prev = current;

	*node = next_node;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the doubly linked list
 * Return: ascending order of integers
 * NIL if size < 2
 *
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *current, *trail_back, *aux;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	current = *list;
	while (current && current->next)
	{
		if (current->n > current->next->n)
		{
			aux = current;
			swap_nodes(&aux, list);
			print_list(*list);

			current = *list;
			trail_back = aux;

			while (trail_back && trail_back->prev)
			{
				if (trail_back->n < trail_back->prev->n)
				{
					aux = trail_back->prev;

					swap_nodes(&(aux), list);
					trail_back = aux->next;
				}

				trail_back = trail_back->prev;
			}
		}
		current = current->next;
	}
}
