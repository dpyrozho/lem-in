/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:58:08 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 17:58:09 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char				*h_gesv(char *str, t_rooms *point, t_op *s)
{
	char			*nstr;
	char			*bstr;
	char			*def;

	def = strchr(str, '-');
	nstr = ft_strsub((str), 0, def - (str));
	bstr = ft_strsub((str), (unsigned int)(def - (str) + 1),
ft_strlen(def) - 1);
	if (ft_strcmp(point->name, nstr) == 0)
	{
		str = def;
		s->index1 = point->index;
	}
	if (ft_strcmp(point->name, bstr) == 0)
	{
		str[def - str + 1] = '\0';
		s->index2 = point->index;
	}
	ft_memdel((void**)(&nstr));
	ft_memdel((void**)(&bstr));
	return (str);
}

int					get_svyazi(t_op *s, char *str)
{
	t_rooms			*point;

	point = s->rooms;
	if (!s->m_smezhn)
		malloc_matrix(s);
	while (point != NULL)
	{
		str = h_gesv(str, point, s);
		if (ft_strcmp(str, "-") == 0)
		{
			add_to_matrix(s, s->index1, s->index2);
			return (1);
		}
		point = point->next;
	}
	return (0);
}

t_rooms				*take_start(int index, t_rooms *p)
{
	while (p != NULL)
	{
		if (p->index == index)
			break ;
		p = p->next;
	}
	return (p);
}

void				print_mw(t_op *s, t_que *que)
{
	t_way			*way;
	t_rooms			*blo;

	way = malloc(sizeof(way));
	while (que->elem && que->elem->index != s->s_ind)
	{
		ft_push_front(&(way->this), que->elem);
		que->elem = que->elem->prev;
	}
	blo = way->this;
	while (blo->index != s->e_ind)
		blo = blo->next;
	blo->next = NULL;
	s->way = way;
	return ;
}

int					main(void)
{
	t_op			s;

	obnul_str(&s);
	num_ants(&s, 0);
	if (correct_rooms(&s, 0) == 1)
		return (0);
	if (!s.rooms)
	{
		ft_printf("\n%sError. Not enough info or empty\n", KRED);
		return (0);
	}
	find_way(&s, -1, s.s_ind);
	if (!s.way)
		ft_printf("\n%sError. Not enough info.No Way.\n", KRED);
	return (0);
}
