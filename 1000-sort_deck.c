#include "deck.h"

/**
 * _strcmp - function to compare two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: the result
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;

		str2++;
	}

	if (*str1 != *str2)
	{
		return (*str1 - *str2);
	}

	return (0);
}

/**
 * func_getv - function to get the value
 * @cards: the pointer to the card struct
 *
 * Return: the result.
 */

char func_getv(deck_node_t *cards)
{
	if (_strcmp(cards->card->value, "Ace") == 0)
	{
		return (0);
	}
	if (_strcmp(cards->card->value, "1") == 0)
	{
		return (1);
	}
	if (_strcmp(cards->card->value, "2") == 0)
	{
		return (2);
	}
	if (_strcmp(cards->card->value, "3") == 0)
	{
		return (3);
	}
	if (_strcmp(cards->card->value, "4") == 0)
	{
		return (4);
	}
	if (_strcmp(cards->card->value, "5") == 0)
	{
		return (5);
	}
	if (_strcmp(cards->card->value, "6") == 0)
		return (6);
	if (_strcmp(cards->card->value, "7") == 0)
		return (7);
	if (_strcmp(cards->card->value, "8") == 0)
		return (8);
	if (_strcmp(cards->card->value, "9") == 0)
		return (9);
	if (_strcmp(cards->card->value, "10") == 0)
		return (10);
	if (_strcmp(cards->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(cards->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_value - function to sort the values
 * @decks: the poointer to be checked
 *
 * Return: nothing.
 */

void insert_value(deck_node_t **decks)
{
	deck_node_t *it, *ins;
	deck_node_t *tp;

	for (it = (*decks)->next; it != NULL; it = tp)
	{
		tp = it->next;
		ins = it->prev;

		while (ins != NULL && ins->card->kind == it->card->kind &&
			func_getv(ins) > func_getv(it))
		{
			ins->next = it->next;
			if (it->next != NULL)
			{
				it->next->prev = ins;
			}
			it->prev = ins->prev;
			it->next = ins;
			if (ins->prev != NULL)
			{
				ins->prev->next = it;
			}
			else
			{
				*decks = it;
			}
			ins->prev = it;
			ins = it->prev;
		}
	}
}

/**
 * insert_kind - function to sort the kind of cards
 * @decks: the pointer to be checked
 *
 * Return: nothing.
 */

void insert_kind(deck_node_t **decks)
{
	deck_node_t *it, *ins;
	deck_node_t *tp;

	for (it = (*decks)->next; it != NULL; it = tp)
	{
		tp = it->next;
		ins = it->prev;

		while (ins != NULL && ins->card->kind > it->card->kind)
		{
			ins->next = it->next;
			if (it->next != NULL)
			{
				it->next->prev = ins;
			}
			it->prev = ins->prev;
			it->next = ins;
			if (ins->prev != NULL)
			{
				ins->prev->next = it;
			}
			else
			{
				*decks = it;
			}
			ins->prev = it;
			ins = it->prev;
		}
	}
}

/**
 * sort_deck - function to sort the deck
 * @deck: the pointer to be checked
 *
 * Return: nothing.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
		return;
	}

	insert_kind(deck);
	insert_value(deck);
}
