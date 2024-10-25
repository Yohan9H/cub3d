/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:56:16 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/25 11:09:37 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		verif_char_no_accept(char c)
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
				ft_fprintf("Error : char no accepted in your map\n");
				exit_clean(data, EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}
