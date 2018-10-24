/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:58:44 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 17:58:53 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		lem_help(t_op *s, int i, t_rooms *hitrou)
{
	while (i <= s->ants)
	{
		i = fill_in_lem_to_rooms(s, hitrou, i);
		hitrou = s->way->this;
		write_nom_ants(hitrou);
		hitrou = s->way->this;
		podvin_ant(s, hitrou);
		hitrou = s->way->this;
	}
}

static void		lem_help2(t_op *s, t_rooms *hitrou)
{
	while (hitrou != NULL)
	{
		while (hitrou && hitrou->n_ant == -1)
			hitrou = hitrou->next;
		if (!hitrou)
			exit(1);
		write_nom_ants(hitrou);
		hitrou = s->way->this;
		podvin_ant(s, hitrou);
		hitrou = s->way->this;
	}
}

int				push_lem(t_op *s)
{
	t_rooms		*hitrou;
	int			i;

	i = 1;
	if (s->way)
		hitrou = s->way->this;
	else
	{
		ft_printf("\n\x1B[31mError. No Way\n");
		exit(1);
	}
	if (!hitrou->prev)
		ft_printf("\n\x1B[31mUNCORRECT LINKS (NO_POSSIBLE)\n");
	if (hitrou->index != s->e_ind)
	{
		while (hitrou->next->index != s->e_ind)
			hitrou = hitrou->next;
		hitrou->next->prev = hitrou;
	}
	hitrou = s->way->this;
	ft_printf("\n");
	lem_help(s, i, hitrou);
	lem_help2(s, hitrou);
	exit(1);
}
