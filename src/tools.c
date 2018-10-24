/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:21:31 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/06/16 18:21:38 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
**	void    ft_free_3d(char ***mas, int n)
**	{
**	    int     i;
**
**	    i = 0;
**	    if (*mas)
**	        while (i < n && (*mas)[i])
**	        {
**	            if ((*mas)[i])
**	                ft_memdel((void**)(&((*mas)[i++])));
**	        }
**	    if (*mas)
**	        ft_memdel((void**)(&(*mas)));
**	}
**
**
**	void    free_struk(t_op *s)
**	{
**	    t_rooms   *r_p;
**
**		if (s->line)
**			ft_memdel((void**)(&s->line));
**		ft_free_3d(&s->m_smezhn, s->iter + 1);
**		while (s->way->this != NULL)
**		{
**			if (s->way->this->name && s->way->this->index != s->e_ind)
**				ft_memdel((void**)(&s->way->this->name));
**	        r_p = s->way->this;
**			s->way->this = s->way->this->next;
**	        if (r_p->index != s->e_ind)
**	            ft_memdel((void**)(&r_p));
**		}
**		while (s->rooms != NULL)
**		{
**			if (s->rooms->name)
**	        {
**	            ft_memdel((void**)(&s->rooms->name));
**	            r_p = s->rooms;
**
**	            ft_memdel((void**)(&r_p));
**	        }
**	        s->rooms = s->rooms->next;
**		}
**	    if (s->rooms)
**		    ft_memdel((void**)(&s->rooms));
**	    if (s->que)
**	        ft_memdel((void**)(&s->que));
**	    if (s->way)
**		    ft_memdel((void**)(&s->way));
**	}
*/

int				obnul_str(t_op *s)
{
	s->rooms = NULL;
	s->iter = 0;
	s->way = NULL;
	s->que = NULL;
	s->line = "\0";
	s->ants = 0;
	s->rooms = NULL;
	s->que = NULL;
	s->way = NULL;
	s->m_s = 0;
	s->m_e = 0;
	s->m_smezhn = NULL;
	s->iter = 0;
	s->s_ind = 0;
	s->e_ind = 0;
	s->fd = 0;
	return (0);
}

static void		mem_he(char **room_inf, t_op *s, t_rooms *komn)
{
	komn->x = ft_atoi(room_inf[1]);
	komn->y = ft_atoi(room_inf[2]);
	komn->index = s->iter;
	if (room_inf[0][0] == 'L' || ft_strchr(room_inf[0], '-'))
	{
		ft_printf("%sInvalid room name\n", KRED);
		exit(1);
	}
	komn->name = ft_strdup(room_inf[0]);
	komn->prev = NULL;
	komn->n_ant = -1;
	s->iter++;
}

void			my_memorika(char **room_inf, t_op *s)
{
	t_rooms		*komn;
	t_rooms		*point;

	point = s->rooms;
	komn = malloc(sizeof(t_rooms));
	if (!komn)
		exit(1);
	if (point == NULL)
	{
		s->rooms = komn;
		s->rooms->next = NULL;
	}
	else
	{
		while (point && point->next != NULL)
			point = point->next;
		point->next = komn;
		point->prev = NULL;
		point->next->next = NULL;
		komn->next = NULL;
	}
	mem_he(room_inf, s, komn);
}
