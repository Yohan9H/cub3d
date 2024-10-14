/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:05 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 18:50:16 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, t_data *fcl)
{
	if (keycode == ESC)
		exit_clean(fcl, EXIT_SUCCESS);
	return (0);
}

int	handle_close(t_data *fcl)
{
	exit_clean(fcl, EXIT_SUCCESS);
	return (0);
}
