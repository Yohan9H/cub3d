/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:56:16 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/30 17:56:39 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(t_data *data)
{
	ft_fprintf("Error\nbad ID\n");
	exit_clean(data, EXIT_FAILURE);
}

char	**malloc_ptr(t_data *data, int skip_endl)
{
	char	**cpy;
	int		x;
	int		nb_malloc;

	nb_malloc = 0;
	x = skip_endl;
	while (data->game->map[x])
	{
		nb_malloc++;
		x++;
	}
	cpy = (char **)malloc(sizeof(char *) * (nb_malloc + 1));
	if (!cpy)
		exit_clean(data, EXIT_FAILURE);
	return (cpy);
}

int	verif_char_no_accept(char c)
{
	if (c == '1' || c == '0' || ft_isspace(c) == 1)
		return (1);
	return (0);
}

void	check_if_char_no_accept(t_data *data, char **map)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (verif_char_no_accept(map[x][y]) != 1)
			{
				ft_fprintf("Error\nchar no accepted in your map\n");
				exit_clean(data, EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}
