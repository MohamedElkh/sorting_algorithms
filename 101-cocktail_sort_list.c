#include "sort.h"

/**
 * sw_node_head - function to swap in doubly linked list
 * @list: the list to be checked
 * @tl: the tail to be checked
 * @shk: the shk to be checked
 *
 * Return: nothing.
 */

void sw_node_head(listint_t **list, listint_t **tl, listint_t **shk)
{
	listint_t *tp = (*shk)->next;

	if ((*shk)->prev != NULL)
	{
		(*shk)->prev->next = tp;
	}
	else
	{
		*list = tp;
	}
	tp->prev = (*shk)->prev;
	(*shk)->next = tp->next;

	if (tp->next != NULL)
	{
		tp->next->prev = *shk;
	}
	else
	{
		*tl = *shk;
	}
	(*shk)->prev = tp;
	tp->next = *shk;
	*shk = tp;
}

/**
 * sw_node_bh - function to swap the node in doubly linked list
 * @list: the list to be checked
 * @tl: the tail to be checked
 * @shk: point to the current swaping node
 *
 * Return: nothing
 */

void sw_node_bh(listint_t **list, listint_t **tl, listint_t **shk)
{
	listint_t *tp = (*shk)->prev;

	if ((*shk)->next != NULL)
	{
		(*shk)->next->prev = tp;
	}
	else
	{
		*tl = tp;
	}
	tp->next = (*shk)->next;
	(*shk)->prev = tp->prev;

	if (tp->prev != NULL)
		tp->prev->next = *shk;
	else
		*list = *shk;

	(*shk)->next = tp;
	tp->prev = *shk;
	*shk = tp;
}

/**
 * cocktail_sort_list - function to swap the node in doubly linked list
 * @list: the list to be checked
 *
 * Return: nothing.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tl;
	listint_t *shk;
	bool check = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (tl = *list; tl->next != NULL;)
	{
		tl = tl->next;
	}

	while (check == false)
	{
		check = true;
		for (shk = *list; shk != tl; shk = shk->next)
		{
			if (shk->n > shk->next->n)
			{
				sw_node_head(list, &tl, &shk);
				print_list((const listint_t *)*list);
				check = false;

			}
		}
		for (shk = shk->prev; shk != *list; shk = shk->prev)
		{
			if (shk->n < shk->prev->n)
			{
				sw_node_bh(list, &tl, &shk);
				print_list((const listint_t *)*list);
				check = false;
			}
		}
	}
}
