/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:03:56 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 10:01:09 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_id_colors(t_data *data, char *id, char *str)
{
	if (ft_strncmp(id, "F", 2) == 0)
	{
		verif_str_colors(data, str);
		data->pars->f = 1;
	}
	else if (ft_strncmp(id, "C", 2) == 0)
	{
		verif_str_colors(data, str);
		data->pars->c = 1;
	}
}

void	verif_digit(t_data *data, char c)
{
	if (ft_isdigit((int)c) != 1)
	{
		ft_fprintf("Error : RGB is bad (...,...,...)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	verif_str_colors(t_data *data, char *str)
{
	int		i;
	int		nb1;
	int		nb2;
	int		nb3;

	i = ft_strlen(data->pars->id);
	while (str[i] && ft_isdigit((int)str[i]) != 1)
		i++;
	verif_digit(data, str[i]);
	nb1 = ft_atoi(&str[i]);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	verif_digit(data, str[i]);
	nb2 = ft_atoi(&str[i]);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	verif_digit(data, str[i]);
	nb3 = ft_atoi(&str[i]);
	if (nb1 < 0 || nb2 < 0 || nb3 < 0 || nb1 > 255 || nb2 > 255 || nb3 > 255)
	{
		ft_fprintf("Error : bad value in RGB (0 - 255)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}
