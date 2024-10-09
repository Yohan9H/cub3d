/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:06:52 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/09 11:19:24 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H
# include "cub3d.h"
# define N_EXIT -1

typedef enum s_keycode
{
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
}	t_keycode;

#endif