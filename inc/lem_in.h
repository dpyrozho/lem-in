/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:59:40 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/05/17 17:01:10 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define CO3 {ft_printf("\n\x1B[31mInvalid coords (overleap)\n");exit(1);};
# define CO1 {ft_printf("\n\x1B[31mIncorrect room_info(COORDS_X)\n");exit(1);};
# define CO2 {ft_printf("\n\x1B[31mIncorrect room_info(COORDS_Y)\n");exit(1);};
# define NE	{ft_printf("%s\nError. Give me end, bro\n", KRED);exit(1);};
# define SE	{ft_printf("%s\nError. Give me start, bro\n", KRED);exit(1);};
# define RF {choose(s);continue;};
# define EL {if (i != 3 && i != 1)inc_line(s);};
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				index;
	struct s_rooms	*next;
	struct s_rooms	*prev;
	int				status;
	int				n_ant;
	int				tyag;
}					t_rooms;

typedef	struct		s_que
{
	t_rooms			*elem;
	struct s_que	*next;
}					t_que;

typedef	struct		s_way
{
	t_rooms			*this;
	struct s_way	*next;
}					t_way;

typedef struct		s_op
{
	char			*line;
	int				ants;
	t_rooms			*rooms;
	t_que			*que;
	t_way			*way;
	int				m_s;
	int				m_e;
	char			**m_smezhn;
	int				iter;
	int				s_ind;
	int				e_ind;
	int				fd;
	int				index1;
	int				index2;
}					t_op;

void				ft_free_3d(char ***mas, int n);
void				add_to_matrix(t_op *s, int i1, int i2);
int					malloc_matrix(t_op *s);
void				ft_push_front(t_rooms **head, t_rooms *room);
int					num_ants(t_op *s, int i);
int					check_room_inf(t_op *s, char **room_inf, int i);
int					correct_rooms(t_op *s, int i);
int					find_way(t_op *s, int i, int ind);
int					get_svyazi(t_op *s, char *str);
void				my_memorika(char **room_inf, t_op *s);
t_rooms				*take_start(int index, t_rooms *p);
void				print_mw(t_op *s, t_que *que);
int					fill_in_lem_to_rooms(t_op *s, t_rooms *lst, int i);
int					write_nom_ants(t_rooms *lst);
int					podvin_ant(t_op *s, t_rooms *lst);
int					push_lem(t_op *s);
void				check_inf(char *str, t_op *s);
int					num_ants(t_op *s, int i);
int					check_room_inf(t_op *s, char **room_inf, int i);
void				corr_start(t_op *s);
void				corr_end(t_op *s);
void				choose(t_op *s);
void				inc_line(t_op *s);
int					corr_line(t_op *s, int i, char **room_inf);
int					corr_sv(t_op *s, char **room_inf);
int					push_lem(t_op *s);
void				free_struk(t_op *s);
int					obnul_str(t_op *s);

#endif
