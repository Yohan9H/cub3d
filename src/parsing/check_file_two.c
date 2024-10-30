/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:03:56 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/30 14:33:00 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_id_colors(t_data *data, char *id, char *str)
{
	if (ft_strncmp(id, "F", 2) == 0)
	{
		if (data->pars->f == 1)
		{
			ft_fprintf("Error\nsame ID found\n");
			exit_clean(data, EXIT_FAILURE);
		}
		verif_str_colors(data, str);
		data->pars->f = 1;
	}
	else if (ft_strncmp(id, "C", 2) == 0)
	{
		if (data->pars->c == 1)
		{
			ft_fprintf("Error\nsame ID found\n");
			exit_clean(data, EXIT_FAILURE);
		}
		verif_str_colors(data, str);
		data->pars->c = 1;
	}
}

void	verif_digit(t_data *data, char c)
{
	if (ft_isdigit((int)c) != 1)
	{
		ft_fprintf("Error\nRGB is bad (...,...,...)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	svg_nb_in_data(t_data *data, int r, int v, int b)
{
	if (data->pars->id[0] == 'F')
	{
		data->pars->f_rvb->r = r;
		data->pars->f_rvb->v = v;
		data->pars->f_rvb->b = b;
	}
	if (data->pars->id[0] == 'C')
	{
		data->pars->c_rvb->r = r;
		data->pars->c_rvb->v = v;
		data->pars->c_rvb->b = b;
	}
}

void	verif_str_colors(t_data *data, char *str)
{
	int		i;
	int		nb1;
	int		nb2;
	int		nb3;

	i = skip_id(data, data->pars->line);
	while (str[i] && ft_isdigit((int)str[i]) != 1)
		i++;
	verif_digit(data, str[i]);
	nb1 = ft_atoi(&str[i]);
	skip_virgule_space(str, &i);
	verif_digit(data, str[i]);
	nb2 = ft_atoi(&str[i]);
	skip_virgule_space(str, &i);
	verif_digit(data, str[i]);
	nb3 = ft_atoi(&str[i]);
	svg_nb_in_data(data, nb1, nb2, nb3);
	if (nb1 < 0 || nb2 < 0 || nb3 < 0 || nb1 > 255 || nb2 > 255 || nb3 > 255)
	{
		ft_fprintf("Error\nbad value in RGB (0 - 255)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

int	skip_id(t_data *data, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isalpha(line[i]) != 1)
		i++;
	i += ft_strlen(data->pars->id);
	return (i);
}
