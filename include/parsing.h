/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:46:36 by yohurteb          #+#    #+#             */
/*   Updated: 2024/11/04 10:34:36 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "cub3d.h"

typedef struct s_data	t_data;
typedef struct s_map	t_map;

typedef struct s_map
{
	char	*line;
	t_map	*next;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rvb
{
	int	r;
	int	v;
	int	b;
}	t_rvb;

typedef struct s_pars
{
	t_map		*head_map;
	t_point		*size_tab;
	t_rvb		*c_rvb;
	t_rvb		*f_rvb;
	char		*line;
	char		*id;
	int			fd;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			skip_endl;
	int			end_map;
}	t_pars;

char	**ft_strdup_double_array(t_data *data, char **s1);

void	verif_good_map(t_data *data);

int		found_map(char *line);

void	freetab(char **com);

void	verif_id_colors(t_data *data, char *id, char *str);

void	verif_str_colors(t_data *data, char *str);

int		check_all_found(t_data *data, t_pars *pars);

void	check_file(t_data *data);

void	parsing(t_data *data, int ac, char **av);

void	check_map(t_data *data);

void	endl_become_zero_in_endmap(t_data *data, char **map);

void	verif_endl_in_map(t_data *data, char **map);

void	skip_endl(t_data *data, char **map);

int		is_player(t_data *data, char c);

int		check_char(char c);

void	del_pos_player(t_data *data, char **tab);

void	reset_value_map(t_data *data);

void	check_if_player(t_data *data, char c, int y, int x);

int		skip_id(t_data *data, char *line);

void	skip_virgule_space(char *str, int *i);

void	check_if_char_no_accept(t_data *data, char **map);

char	**malloc_ptr(t_data *data, int skip_endl);

void	print_error(t_data *data);

#endif