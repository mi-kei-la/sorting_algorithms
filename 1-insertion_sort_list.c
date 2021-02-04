#include "sort.h"

/**
  * insertion_sort_list - sort list with insertion method
  *
  * @list: double pointer to head of list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp != NULL)
	{
		j = tmp->next;
		i = tmp;
		tmp = tmp->next;
		if (j->n < i->n)
		{
			while ((i->prev != NULL) && (j->n < i->prev->n))
				i = i->prev;
			insert_node(i, j, list);
			print_list(*list);
		}
		if (tmp->next == NULL)
			break;
	}
}

/**
  * insert_node - insert node and move j
  *
  * @i: pointer to node, insert to previous node
  * @j: pointer to node to insert
  * @list: double pointer to list
  */

void insert_node(listint_t *i, listint_t *j, listint_t **list)
{
	if (j->next == NULL && i->prev != NULL)
	{
		j->prev->next = NULL;
		i->prev->next = j;
		j->prev = i->prev;
		i->prev = j;
		j->next = i;
	}
	else if (j->next != NULL && i->prev == NULL)
	{
		j->prev->next = j->next;
		j->next->prev = j->prev;
		j->prev = NULL;
		j->next = i;
		i->prev = j;
		*list = j;
		(*list)->next = j->next;
	}
	else if (j->next == NULL && i->prev == NULL)
	{
		j->prev->next = NULL;
		j->prev = NULL;
		j->next = i;
		i->prev = j;
		*list = j;
		(*list)->next = j->next;
	}
	else
	{
		j->prev->next = j->next;
		j->next->prev = j->prev;
		j->prev = i->prev;
		i->prev->next = j;
		i->prev = j;
		j->next = i;
	}
}
