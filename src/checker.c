/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:38:00 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/07 16:38:01 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				corr_sv(t_op *s, char **room_inf)
{
	if (s->m_e == 0)
		NE;
	if (s->m_s == 0)
		SE;
	if (ft_strstr(room_inf[0], "-") == 0)
	{
		ft_printf("%s\nError, bad connection, bro\n", KRED);
		if (s->rooms)
			find_way(s, -1, s->s_ind);
		exit(1);
	}
	if (get_svyazi(s, room_inf[0]) == 0)
	{
		ft_printf("\n\x1B[31mError. Invalid connections\n");
		if (s->rooms)
			find_way(s, -1, s->s_ind);
		return (1);
	}
	return (0);
}

int				corr_line(t_op *s, int i, char **room_inf)
{
	if (i == 3)
	{
		if (check_room_inf(s, room_inf, 0) == 1)
			return (1);
		else
			return (0);
	}
	if (i == 1)
	{
		if (corr_sv(s, room_inf) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

int				correct_rooms(t_op *s, int i)
{
	char		**room_inf;

	while (get_next_line(s->fd, &s->line) > 0)
	{
		ft_printf("%s\n", s->line);
		i = 0;
		if (s->line[0] == '#')
			RF;
		if (s->line[0] != '#' || s->line[0] != '\0')
		{
			room_inf = ft_strsplit(s->line, ' ');
			while (room_inf[i] != NULL)
				i++;
			EL;
			if (corr_line(s, i, room_inf) == 1)
				return (1);
			else
				continue;
		}
	}
	return (0);
}
