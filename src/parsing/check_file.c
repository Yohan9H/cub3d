/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:52:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/21 15:49:54 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_str(t_data *data, char *str, char *word)
{
	int		i;
	int		len_word;

	len_word = ft_strlen(word);
	if (ft_strncmp(str, "./path_to_the_", 14) != 0)
	{
		free(str);
		ft_fprintf("Error 1: your path in your file is bad for -%s-\n", word);
		exit_clean(data, EXIT_FAILURE);
	}
	i = 14;
	if (ft_strncmp(&str[i], word, len_word - 1) != 0)
	{
		free(str);
		ft_fprintf("Error 2: your path in your file is bad for -%s-\n", word);
		exit_clean(data, EXIT_FAILURE);
	}
	i += len_word;
	if (ft_strncmp(&str[i], "_texture", 9) != 0)
	{
		free(str);
		ft_fprintf("Error 3: your path in your file is bad for -%s-\n", word);
		exit_clean(data, EXIT_FAILURE);
	}
}

void	take_and_verif_str(t_data *data, char *line, char *word)
{
	char	*str;
	int		i;

	if (line == NULL)
		return ;
	i = skip_id(data, line);
	while (line[i] && line[i] != '.')
		i++;
	str = ft_strdup_esc(&line[i]);
	if (!str)
	{
		free(str);
		exit_clean(data, EXIT_FAILURE);
	}
	verif_str(data, str, word);
	free(str);
}

void	check_line(t_data *data, char *id, char *line)
{
	if (line[0] == '\n')
		return ;
	if (ft_strncmp(id, "NO", 3) == 0)
	{
		take_and_verif_str(data, line, "north");
		data->pars->no = 1;
	}
	else if (ft_strncmp(id, "SO", 3) == 0)
	{
		take_and_verif_str(data, line, "south");
		data->pars->so = 1;
	}
	else if (ft_strncmp(id, "WE", 3) == 0)
	{
		take_and_verif_str(data, line, "west");
		data->pars->we = 1;
	}
	else if (ft_strncmp(id, "EA", 3) == 0)
	{
		take_and_verif_str(data, line, "east");
		data->pars->ea = 1;
	}
	else
		verif_id_colors(data, id, line);
}

void	take_id(t_data *data, char *line)
{
	int		i;

	i = 0;
	if (line == NULL || line[i] == '\n')
		return ;
	while (line[i] && ft_isalpha(line[i]) != 1)
		i++;
	if (data->pars->id != NULL)
		free(data->pars->id);
	data->pars->id = ft_strdup_esc(&line[i]);
	if (!data->pars->id)
		exit_clean(data, EXIT_FAILURE);
}

void	check_file(t_data *data, char *file)
{
	data->pars->fd = open(file, O_RDONLY);
	if (data->pars->fd == -1)
	{
		ft_fprintf("Error : file not found\n");
		exit_clean(data, EXIT_FAILURE);
	}
	data->pars->line = get_next_line(data->pars->fd);
	take_id(data, data->pars->line);
	check_line(data, data->pars->id, data->pars->line);
	while (data->pars->line != NULL && check_all_found(data->pars) != 1)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
		if (data->pars->line == NULL)
			break;
		take_id(data, data->pars->line);
		check_line(data, data->pars->id, data->pars->line);
	}
	if (data->pars->line == NULL)
	{
		ft_fprintf("Error : miss value in your file\n");
		exit_clean(data, EXIT_FAILURE);
	}
}
