/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:46:36 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:18 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include "cub3d.h"

typedef struct s_data t_data;

typedef struct s_pars
{
	char	*file;
	int		fd;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}	t_pars;

void	check_file(t_data *data);

void	parsing(t_data *data, int ac, char **av);

#endif