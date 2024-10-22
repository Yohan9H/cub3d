/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:02:05 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/22 15:30:20 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_clean(data, EXIT_SUCCESS);
	return (0);
}

int	handle_close(t_data *data)
{
	exit_clean(data, EXIT_SUCCESS);
	return (0);
}
