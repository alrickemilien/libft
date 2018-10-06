/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:25:59 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 17:32:47 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply quick sort on linked list
*/

static t_list	*get_last_element(t_list *list)
{
	while (list != NULL && list->next != NULL)
		list = list->next;
	return (list);
}

static void		swap_list_nodes(t_list *prev, t_list **cursor, t_list **tail)
{
	t_list *tmp;

	if (prev)
		prev->next = (*cursor)->next;
	tmp = (*cursor)->next;
	(*cursor)->next = NULL;
	(*tail)->next = *cursor;
	*tail = *cursor;
	*cursor = tmp;
}

/*
** Partitioning the list taking the last element as the pivot
*/

static t_list	*partition(
		t_list *first,
		t_list *last,
		t_list **new_first,
		t_list **new_last,
		int (*sort)(void*, void*))
{
	t_list *pivot;
	t_list *prev;
	t_list *tail;
	t_list *cursor;

	pivot = last;
	cursor = first;
	tail = pivot;
	prev = NULL;
	while (cursor != pivot)
	{
		if (sort(cursor->content, pivot->content) < 0)
		{
			if ((*new_first) == NULL)
				(*new_first) = cursor;
			prev = cursor;
			cursor = cursor->next;
		}
		else
			swap_list_nodes(prev, &cursor, &tail);
	}
	if ((*new_first) == NULL)
		(*new_first) = pivot;
	(*new_last) = tail;
	return (pivot);
}

t_list	*quick_sort_list(
		t_list *first,
		t_list *last,
		int (*sort)(void*, void*))
{
	t_list *tmp;
	t_list *new_first;
	t_list *new_last;
	t_list *pivot;

	new_first = NULL;
	new_last = NULL;
	if (!first || first == last)
		return (first);
	pivot = partition(first, last, &new_first, &new_last, sort);
	if (new_first != pivot)
	{
		tmp = new_first;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		new_first = quick_sort_list(new_first, tmp, sort);
		tmp = get_last_element(new_first);
		tmp->next = pivot;
	}
	pivot->next = quick_sort_list(pivot->next, new_last, sort);
	return (new_first);
}
