#include "sort.h"

/**
  * insertion_sort_list - sort list with insertion method
  *
  * @list: double pointer to head of list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *tmp = *list;

	if (list == NULL || tmp->next == NULL)
		return;

	printf("before loop\n");
	while (tmp != NULL)
	{
		printf("still in memory\n");
		j = tmp->next;
		i = tmp;
		if (j->n < i->n)
		{
			printf("entered if\n");
			while ((i->prev != NULL) && (j->n < i->prev->n))
			{
				i = i->prev;
			}
			printf("i was moved, value of i: %d\n", i->n);
			printf("j will be moved, value: %d\n", j->n);
			insert_node(i, j, list);
			print_list(*list);
		}
		tmp = tmp->next;
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
	printf("inserting\n");
	if (j->next == NULL)
		j->prev->next = NULL;
	else
	{
		j->prev->next = j->next;
		j->next->prev = j->prev;
	}
	if (i->prev == NULL)
	{
		*list = j;
		i->prev = j;
		j->prev = NULL;
		j->next = i;
	}
	else
	{
		i->prev->next = j;
		j->prev = i->prev;
		i->prev = j;
		j->next = i;	
	}
}
