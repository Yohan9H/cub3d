/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:46:36 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 11:32:57 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include "cub3d.h"

typedef struct s_data t_data;

typedef struct s_map
{
	char	*line;
	t_map	*next;
}	t_map;

typedef struct s_pars
{
	t_map	*head_map;
	char	*line;
	char	*id;
	int		fd;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	
}	t_pars;

void	verif_id_colors(t_data *data, char *id, char *str);

void	verif_str_colors(t_data *data, char *str);

int		check_all_found(t_pars *pars);

void	check_file(t_data *data, char *file);

void	parsing(t_data *data, int ac, char **av);

#endif