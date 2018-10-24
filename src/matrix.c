/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:17:27 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/07 11:17:30 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				malloc_matrix(t_op *s)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	s->m_smezhn = (char**)malloc(sizeof(char*) * (s->iter + 1));
	while (i < s->iter)
	{
		j = 0;
		s->m_smezhn[i] = (char*)malloc(sizeof(char) * (s->iter + 1));
		while (j < s->iter)
		{
			s->m_smezhn[i][j] = '0';
			j++;
		}
		s->m_smezhn[i][s->iter] = '\0';
		i++;
	}
	s->m_smezhn[i] = NULL;
	return (0);
}

void			add_to_matrix(t_op *s, int i1, int i2)
{
	if (i1 == -1 || i2 == -1)
	{
		ft_printf("\n\x1B[31mINCORRECT LINKS");
		exit(1);
	}
	s->m_smezhn[i1][i2] = '1';
	s->m_smezhn[i2][i1] = '1';
}

void			ft_push_front(t_rooms **head, t_rooms *room)
{
	room->next = *head;
	*head = room;
}
