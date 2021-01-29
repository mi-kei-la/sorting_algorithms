#include "sort.h"

/**
 * insertion_sort_list - sort a list by inserting nodes in correct order
 *
 * @list: double pointer to head
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *aux = NULL, *extra = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		aux = tmp;
		if ((aux->prev->n > aux->n) && (aux->next != NULL))
		{
			while ((aux->prev) != NULL && (aux->prev->n > tmp->n))
				aux = aux->prev;
			/* create pointer to compare, move tmp to next node */
			extra = tmp;
			if (tmp->next != NULL)
				tmp = tmp->next;
			/* assign new values*/
			if (aux->prev != NULL) /* node moves to middle of the list */
			{
				extra->prev = aux->prev;
				extra->next = aux;
				extra->prev->next = extra;
				aux->prev = extra;
			}
			else /* move node to head */
			{
				extra->prev = NULL;
				extra->next = aux;
				aux->prev = extra;
				*list = extra;
			}
		}
		else
			tmp = tmp->next;
	}
}
