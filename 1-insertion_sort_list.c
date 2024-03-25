#include "sort.h"

int size_of(listint_t *list);

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: pointer to the list that need to be sorted.
 *
 * Return: void, no return.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_node, *temp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert_node = current->prev;

		while (insert_node != NULL && current->n < insert_node->n)
		{
			insert_node->next = current->next;

			if (current->next != NULL)
				current->next->prev = insert_node;

			current->prev = insert_node->prev;
			current->next = insert_node;

			if (insert_node->prev != NULL)
				insert_node->prev->next = current;
			else
				*list = current;

			insert_node->prev = current;
			insert_node = current->prev;
			print_list(*list);
		}
	}
}

/**
 * size_of - calculate the size of the given doubly linked list.
 * @list: pointer to the list.
 *
 * Return: size of the list.
 */
int size_of(listint_t *list)
{
	int list_size = 0;

	while (list != NULL)
	{
		list_size++;
		list = list->next;
	}

	return (list_size);
}

