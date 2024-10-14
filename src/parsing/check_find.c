/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 14:09:25 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_find(t_pars *pars)
{
	if ((pars->c + pars->f + pars->no + pars->we + pars->so + pars->ea) == 6)
		return (1);
	else
		return (0);
}
