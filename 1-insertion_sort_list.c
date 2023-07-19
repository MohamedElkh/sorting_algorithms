#include "sort.h"

/**
 * insertion_sort_list - function to sort doubly linked list
 * @list: the doubly linked list to sort
 *
 * Return: nothing.
 */

void insertion_sort_list(listint_t **list)
{
	bool flg = false;
	listint_t *tp = NULL;
	listint_t *ax = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	tp = *list;
	while (tp->next)
	{
		if (tp->n > tp->next->n)
		{
			tp->next->prev = tp->prev;
			if (tp->next->prev)
				tp->prev->next = tp->next;
			else
				*list = tp->next;
			tp->prev = tp->next;
			tp->next = tp->next->next;
			tp->prev->next = tp;
			if (tp->next)
				tp->next->prev = tp;
			tp = tp->prev;
			print_list(*list);
			if (tp->prev && tp->prev->n > tp->n)
			{
				if (!flg)
				{
					ax = tp->next;
				}
				flg = true;
				tp = tp->prev;
				continue;
			}
		}
		if (!flg)
			tp = tp->next;
		else
			tp = ax, flg = false;
	}
}
