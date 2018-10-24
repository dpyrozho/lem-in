/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:45:35 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/07 16:45:36 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void			norma2(t_que **que, t_rooms *prev)
{
	(*que)->elem->status = 2;
	(*que)->elem->prev = prev;
	(*que)->elem->tyag = prev->tyag + 1;
}

static void			norma1(t_op *s, t_que **que, t_rooms **p, int i)
{
	*que = malloc(sizeof(t_que));
	*p = s->rooms;
	(*que)->elem = take_start(i, *p);
	(*que)->next = NULL;
}

static void			norma(t_op *s, int i, int ind, t_rooms *prev)
{
	t_que			*que;
	t_que			*head;
	t_rooms			*p;

	if (s->m_smezhn[ind][i] == '1' && s->m_smezhn[i][ind] == '1')
	{
		norma1(s, &que, &p, i);
		if (que->elem && que->elem->status != 3 && que->elem->status != 2)
		{
			norma2(&que, prev);
			if (que->elem->index == s->e_ind)
				print_mw(s, que);
			if (s->que == NULL)
				s->que = que;
			else
			{
				head = s->que;
				while (head->next != NULL)
					head = head->next;
				head->next = que;
			}
		}
	}
}

static	void		norma3(void)
{
	ft_printf("\n%sError. Not enough connections\n", KRED);
	exit(1);
}

int					find_way(t_op *s, int i, int ind)
{
	t_rooms			*prev;

	prev = take_start(ind, s->rooms);
	prev->status = 3;
	while (ind != s->e_ind)
	{
		(!s->m_smezhn) ? norma3() : 0;
		while (s->m_smezhn[ind][++i] != '\0')
			if (s->m_smezhn[ind][i] == '1' && s->m_smezhn[i][ind] == '1')
				norma(s, i, ind, prev);
		i = 0;
		if (s->que == NULL)
			push_lem(s);
		if (s->que->elem->status == 3)
			s->que = s->que->next;
		if (s->que != NULL)
		{
			prev = s->que->elem;
			ind = s->que->elem->index;
			s->que->elem->status = 3;
		}
		if (ind == 3)
			ind = 3;
	}
	return (0);
}
