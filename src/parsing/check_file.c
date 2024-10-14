/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:52:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 15:25:17 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_str(t_data *data, char *str, char *word)
{
	int		i;
	int		len_word;

	len_word = ft_strlen(word);
	if (ft_strncmp(str, "./path_to_the_", 14) != 0) // ou 13 a voir
	{
		ft_fprintf("Error : your file name is bad\n");
		exit_clean(data, EXIT_FAILURE);
	}
	i = 14;
	if (ft_strncmp(&str[i], word, len_word - 1) != 0)
	{
		ft_fprintf("Error : your file name is bad\n");
		exit_clean(data, EXIT_FAILURE);
	}
	i += len_word - 1;
	if (ft_strncmp(&str[i], "_texture ", 9) != 0)
	{
		ft_fprintf("Error : your file name is bad\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	verif_line(t_data *data, char *id, char *str)
{
	if (ft_strncmp(id, "NO", 3) == 0)
	{
		check_str(data, str, "north");
		data->pars->no = 1;
	}
	else if (ft_strncmp(id, "SO", 3) == 0)
	{
		check_str(data, str, "south");
		data->pars->so = 1;
	}
	else if (ft_strncmp(id, "WE", 3) == 0)
	{
		check_str(data, str, "west");
		data->pars->we = 1;
	}
	else if (ft_strncmp(id, "EA", 3) == 0)
	{
		check_str(data, str, "east");
		data->pars->ea = 1;
	}
	else
		return ;
}

void	check_line(t_data *data, char *line)
{
	char	*id;
	char	*str;
	int		i;

	i = 0;
	if (line == NULL)
		return ;
	while (line[i] && ft_isalpha(line[i]) != 1)
		i++;
	id = ft_strdup_esc(&line[i]);
	if (!id)
		exit_clean(data, EXIT_FAILURE);
	i += ft_strlen(id);
	while (line[i] && line[i] != '.')
		i++;
	str = ft_strdup_esc(&line[i]);
	if (!str)
		exit_clean(data, EXIT_FAILURE);
	verif_line(data, id, str);
}

void	check_file(t_data *data, char *file)
{
	data->pars->fd = open(file, O_RDONLY);
	if (data->pars->fd == -1)
	{
		ft_fprintf("Error : file not find\n");
		exit_clean(data, EXIT_FAILURE);
	}
	data->pars->line = get_next_line(data->pars->fd);
	check_line(data, data->pars->line);
	while (data->pars->line != NULL || check_find(data->pars) != 1)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
		check_line(data, data->pars->line);
		free(data->pars->line);
	}
}
