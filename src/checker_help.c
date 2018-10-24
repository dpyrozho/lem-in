/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:54:29 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 17:54:44 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				check_room_inf(t_op *s, char **room_inf, int i)
{
	t_rooms		*poi;

	check_inf(room_inf[0], s);
	my_memorika(room_inf, s);
	while (room_inf[1][i] >= '0' && room_inf[1][i] <= '9')
		i++;
	if (room_inf[1][i] != '\0')
		CO1;
	i = 0;
	while (room_inf[2][i] >= '0' && room_inf[2][i] <= '9')
		i++;
	if (room_inf[2][i] != '\0')
		CO2;
	poi = s->rooms;
	while (poi->next != NULL)
	{
		if (poi->x == poi->next->x && poi->y == poi->next->y)
			CO3;
		poi = poi->next;
	}
	return (0);
}

void			corr_start(t_op *s)
{
	s->m_s++;
	if (s->m_s > 1)
	{
		ft_memdel((void **)(&s->line));
		ft_printf("\n\x1B[31mERROR. WITH START");
		if (s->rooms)
			find_way(s, -1, s->s_ind);
		exit(1);
	}
	s->s_ind = s->iter;
	ft_memdel((void **)(&s->line));
}

void			corr_end(t_op *s)
{
	s->m_e++;
	if (s->m_e > 1)
	{
		ft_memdel((void **)(&s->line));
		ft_printf("\n\x1B[31mERROR. WITH END");
		if (s->rooms)
			find_way(s, -1, s->s_ind);
		exit(1);
	}
	s->e_ind = s->iter;
	ft_memdel((void **)(&s->line));
}

void			choose(t_op *s)
{
	if (ft_strcmp("##start", s->line) == 0)
		corr_start(s);
	else if (ft_strcmp("##end", s->line) == 0)
		corr_end(s);
}

void			inc_line(t_op *s)
{
	ft_printf("\n\x1B[31mERROR. INCORRECT INPUT or \\n\n");
	find_way(s, 0, 0);
	exit(1);
}
