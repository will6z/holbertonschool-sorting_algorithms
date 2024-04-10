#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked lists of ints
 * 
 * @list: pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *prev, *nxt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		nxt = cur->next;
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			prev = cur->prev;
			if (cur->next != NULL)
			cur->next->prev = prev;
			if (prev->prev != NULL)
			prev->prev->next = cur;
			else
			*list = cur;
		prev->next = cur->next;
		cur->prev = prev->prev;
		cur->next = prev;
		prev->prev = cur;
		print_list(*list);
		}
	cur = nxt;
	}
}
