/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_manipulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:09:29 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 18:09:38 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				fill_in_lem_to_rooms(t_op *s, t_rooms *lst, int i)
{
	lst = s->way->this;
	while (lst->next != NULL)
	{
		if (lst->n_ant == -1)
		{
			lst->n_ant = i;
			i++;
			return (i);
		}
		lst = lst->next;
	}
	if (lst->n_ant == -1)
	{
		lst->n_ant = i;
		i++;
		return (i);
	}
	return (-1);
}

int				write_nom_ants(t_rooms *lst)
{
	while (lst != NULL)
	{
		if (lst->n_ant != -1)
		{
			if (lst->n_ant % 7 == 1)
				ft_printf("%s", KRED);
			else if (lst->n_ant % 7 == 2)
				ft_printf("%s", KGRN);
			else if (lst->n_ant % 7 == 3)
				ft_printf("%s", KYEL);
			else if (lst->n_ant % 7 == 4)
				ft_printf("%s", KBLU);
			else if (lst->n_ant % 7 == 5)
				ft_printf("%s", KMAG);
			else if (lst->n_ant % 7 == 6)
				ft_printf("%s", KCYN);
			else if (lst->n_ant % 7 == 0)
				ft_printf("%s", KWHT);
			ft_printf("L%i-%s ", lst->n_ant, lst->name);
		}
		lst = lst->next;
	}
	ft_printf("\n");
	return (0);
}

int				podvin_ant_help(t_op *s, t_rooms *lst)
{
	while (lst != NULL)
	{
		while (lst && lst->n_ant == -1)
			lst = lst->next;
		while (lst && lst->n_ant != -1)
			lst = lst->next;
		if (!lst)
			return (0);
		if (lst->n_ant == -1)
		{
			lst->n_ant = lst->prev->n_ant;
			while (lst != s->way->this)
			{
				lst = lst->prev;
				lst->n_ant = lst->prev->n_ant;
			}
		}
		if (s->way->this->n_ant == -1)
			return (0);
	}
	return (0);
}

int				podvin_ant(t_op *s, t_rooms *lst)
{
	while (lst != NULL)
	{
		if (lst->index == s->e_ind)
		{
			if (lst->n_ant != -1)
			{
				lst->n_ant = -1;
				lst = s->way->this;
			}
			else
				lst = s->way->this;
			break ;
		}
		lst = lst->next;
	}
	podvin_ant_help(s, lst);
	return (0);
}
