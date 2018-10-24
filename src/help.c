/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:12:41 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 16:12:43 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		hnum(t_op *s)
{
	free(s->line);
	ft_printf("\n\x1B[31mERORR, INVALID NUMBER OF ANTS");
	exit(1);
}

static void		hnum1(t_op *s)
{
	free(s->line);
	get_next_line(s->fd, &s->line);
}

int				num_ants(t_op *s, int i)
{
	while (get_next_line(s->fd, &s->line) > 0)
	{
		ft_printf("%s\n", s->line);
		if (s->line[0] == '#')
			hnum1(s);
		if (s->line[0] >= '0' && s->line[0] <= '9')
		{
			while (s->line[i] >= '0' && s->line[i] <= '9')
				i++;
			if (s->line[i] == '\0')
			{
				s->ants = ft_atoi(s->line);
				if (s->ants <= 0)
					hnum(s);
				free(s->line);
				break ;
			}
			else
				hnum(s);
		}
		else
			hnum(s);
	}
	return (1);
}

void			check_inf(char *str, t_op *s)
{
	t_rooms		*val;

	val = s->rooms;
	while (val != NULL)
	{
		if (ft_strcmp(val->name, str) == 0)
		{
			ft_printf("\n\x1B[31mError. Check name of the "
	"rooms, similiar names");
			exit(10);
		}
		val = val->next;
	}
}
