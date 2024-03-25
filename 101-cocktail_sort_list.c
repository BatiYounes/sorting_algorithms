#include "sort.h"

void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: pointer to the head of a doubly-linked list.
 *
 * Return: void, no return.
 */
void cocktail_sort_list(listint_t **list)
{
	int stirred = 0;
	listint_t *tail, *shaker;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (stirred == 0)
	{
		stirred = 1;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred = 0;
			}
		}
	}
}

/**
 * swap_ahead - function swap a node in a doubly-linked list of integers
 * with the node ahead of it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tail: pointer to the tail of the doubly-linked list of integers.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 *
 * Return: void, no return.
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
	{
		(*shaker)->prev->next = temp;
	}
	else
	{
		*list = temp;
	}

	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = *shaker;
	}
	else
	{
		*tail = *shaker;
	}

	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_behind - function swap a node in a doubly-linked list of integers
 * with the node behind it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tail: pointer to the tail of the doubly-linked list of integers.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
	{
		(*shaker)->next->prev = temp;
	}
	else
	{
		*tail = temp;
	}

	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;

	if (temp->prev != NULL)
	{
		temp->prev->next = *shaker;
	}
	else
	{
		*list = *shaker;
	}

	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

