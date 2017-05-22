/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:06:59 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 17:05:34 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libftprintf/ft_printf.h"

typedef struct			s_code
{
	char				*line;
	int					status;
	struct s_code		*next;
}						t_code;

typedef struct			s_room
{
	char				*name;
	int					status;
	struct s_room		*next;
}						t_room;

typedef struct			s_links
{
	char				**name;
	struct s_links		*next;
}						t_links;

typedef struct			s_startend
{
	char				*start;
	char				*end;
}						t_startend;

typedef struct			s_paths
{
	char				*path;
	int					ants;
	struct s_paths		*next;
}						t_paths;

typedef struct			s_lemin
{
	t_paths				*path;
	int					status;
	struct s_lemin		*next;
}						t_lemin;

t_code					*get_code(t_code *code);
t_room					*get_room(t_room *room, t_code *code);
t_links					*get_links(t_links *links, t_code *code);
int						verif_links(t_links *links, t_room *room);
t_lemin					*get_lemin(int ants, t_lemin *lemin,
												t_room *room, t_links *links);
t_lemin					*new_lemin(t_lemin *lemin, t_links *links,
														t_startend *startend);
t_paths					*new_path(char **names, t_paths *next_paths);
t_lemin					*fill_lemin(t_lemin *lemin, t_links *links,
														t_startend *startend);
t_lemin					*verif_lemin(t_lemin *im, t_startend *startend);
t_lemin					*min_path(t_lemin *lemin);
t_lemin					*ft_goto_lastantz(t_lemin *lemin, int max_ants);
void					print_lemin(t_lemin *lemin, int ants);
void					ft_affich_round_fin(t_lemin *lemin, int max_ants);
void					ft_affich_round(t_lemin *lemin);

int						lst_count_path(t_paths *path);
int						strisdigit(char *s);
int						chariter(char *s, char c);
int						ft_strlen_chr(char *s, char c);
int						get_ants(t_code *code);
int						count_links(t_links *links, char *matchwith);

#endif
