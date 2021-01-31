#include "sort.h"

/**
  * insertion_sort_list - Sort list with insertion method.
  *
  * @list: Double pointer to head of list.
  *
  * This function takes a doubly linked list and sorts it following
  * the insertion sort algorithm. Insertion of nodes is done at an
  * additional function that can be found below. The printing of
  * the list is also done by an external function, although it is
  * not in this file. It returns nothing, since the list is modified.
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL, *j = NULL, *tmp = *list;

	/* Check parameters. */
	if (list == NULL || tmp->next == NULL)
		return;

	/*
	* Loop through list with tmp. J and I will be the nodes to
	* move nodes, j pointing to the current node and i to the
	* position said node will take. After assigning j and i, move
	* tmp again to loop. Print list whenever a change is made, and
	* check that tmp will move to a valid position.
	*/
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
  * insert_node - Insert node at given position.
  *
  * @i: Pointer to node, insert will be to the previous pointer.
  * @j: Node to insert.
  * @list: Double pointer to the head of the list.
  *
  * The position the node should be in will be the prev of i.
  */

void insert_node(listint_t *i, listint_t *j, listint_t **list)
{
	if (j->next == NULL && i->prev != NULL)
	{
		/* Move last node to the middle of the list. */
		j->prev->next = NULL;
		i->prev->next = j;
		j->prev = i->prev;
		i->prev = j;
		j->next = i;
	}
	else if (j->next != NULL && i->prev == NULL)
	{
		/* Move middle node to the beginning of the list. */
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
		/* Move last node to the beginning of the list. */
		j->prev->next = NULL;
		j->prev = NULL;
		j->next = i;
		i->prev = j;
		*list = j;
		(*list)->next = j->next;
	}
	else /* Move middle node to the middle of the list. */
	{
		j->prev->next = j->next;
		j->next->prev = j->prev;
		j->prev = i->prev;
		i->prev->next = j;
		i->prev = j;
		j->next = i;
	}
}
