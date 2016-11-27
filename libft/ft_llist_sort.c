/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:44:47 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 14:17:10 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_swap(t_llnode *n1, t_llnode *n2)
{
	void	*val_tmp;
	size_t	size_tmp;

	val_tmp = n1->val;
	n1->val = n2->val;
	n2->val = val_tmp;
	size_tmp = n1->val_size;
	n1->val_size = n2->val_size;
	n2->val_size = size_tmp;
}

void		ft_llist_sort(t_llist *list, int (*cmp)())
{
	t_llnode	*cur;
	t_llnode	*nxt;
	int			is_sorted;

	if (list == NULL || cmp == NULL)
		return ;
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		cur = list->first;
		nxt = cur->next;
		while (nxt)
		{
			if (cmp(cur->val, nxt->val) > 0)
			{
				aux_swap(cur, nxt);
				is_sorted = 0;
			}
			cur = cur->next;
			nxt = cur->next;
		}
	}
}
