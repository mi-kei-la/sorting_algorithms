#include "sort.h"

/**
  * insertion_sort_list - Sort list with insertion method.
  *
  * @list: Double pointer to head of list.
  *
  * This function parses a doubly linked list, and if the following element
  * is smaller than the current element, they will swap places. Then the
  * condition will be checked again with the previous node, until node is set
  * in place. After that, it will continue traversing the list until the end.
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *aux = NULL;
	int flag = 0;

	if (list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev; /* detach tmp from list */
			if (tmp->next->prev != NULL) /* node != head */
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;
			tmp->prev = tmp->next; /* attach tmp after following node */
			tmp->next = tmp->next->next; /* moving next node backwards */
			tmp->prev->next = tmp;
			if (tmp->next) /* not last node */
				tmp->next->prev = tmp;
			tmp = tmp->prev;
			print_list(*list);
			if (tmp->prev && tmp->prev->n > tmp->n) /* swap again */
			{
				if (flag == 0)
					aux = tmp->next;
				flag = 1;
				tmp = tmp->prev;
				continue;
			}
		}
		if (flag == 0) /* no swaps needed */
			tmp = tmp->next;
		else /* all swaps have been done, continue traversing list */
		{
			tmp = aux;
			flag = 0;
		}
	}
}
