/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:31:24 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/24 11:57:53 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del_pos_player(t_data *data, char **tab)
{
	int		y;
	int		x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (is_player(data, tab[y][x]) == 1)
			{
				tab[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int	check_all_found(t_data *data, t_pars *pars)
{
	if ((pars->c + pars->f + pars->no + pars->we + pars->so + pars->ea) == 6)
		return (1);
	else if ((pars->c + pars->f + pars->no + pars->we + pars->so + pars->ea)
		> 6)
	{
		ft_fprintf("Error : too many texture in your file");
		exit_clean(data, EXIT_FAILURE);
		return (-1);
	}
	else
		return (0);
}

void	reset_value_map(t_data *data)
{
	data->pars->no = 0;
	data->pars->so = 0;
	data->pars->we = 0;
	data->pars->ea = 0;
}

void	check_if_palyer(t_data *data, char c, int y, int x)
{
	if (c == 'N')
	{
		(data->pars->no)++;
		data->game->player->pos.y = y;
		data->game->player->pos.x = x;
	}
	if (c == 'S')
	{
		(data->pars->so)++;
		data->game->player->pos.y = y;
		data->game->player->pos.x = x;
	}
	if (c == 'E')
	{
		(data->pars->ea)++;
		data->game->player->pos.y = y;
		data->game->player->pos.x = x;
	}
	if (c == 'W')
	{
		(data->pars->we)++;
		data->game->player->pos.y = y;
		data->game->player->pos.x = x;
	}
}

void	skip_virgule_space(char *str, int *i)
{
	while (str[*i] && str[*i] != ',')
		(*i)++;
	while (str[*i] && ft_isdigit((int)str[*i]) != 1)
		(*i)++;
}
