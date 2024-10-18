/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_found.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 14:09:25 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_all_found(t_pars *pars)
{
	if ((pars->c + pars->f + pars->no + pars->we + pars->so + pars->ea) == 6)
		return (1);
	else
		return (0);
}

void	freetab(char **com)
{
	int	i;

	i = 0;
	while (com[i])
	{
		free(com[i]);
		i++;
	}
	free(com);
}

int	found_map(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_strdup_double_array(t_data *data, char **s1)
{
	char	**cpy;
	int		j;

	j = 0;
	while (s1[j])
		j++;
	cpy = (char **)malloc(sizeof(char *) * (j + 1));
	if (!cpy)
		exit_clean(data, EXIT_FAILURE);
	j = 0;
	while (s1[j])
	{
		cpy[j] = ft_strdup(s1[j]);
		if (!cpy[j])
		{
			freetab(cpy);
			exit_clean(data, EXIT_FAILURE);
		}
		j++;
	}
	cpy[j] = NULL;
	return (cpy);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	one_or_zero(char c)
{
	if (c == '0' || c == '1')
		return (0);
	return (1);
}
