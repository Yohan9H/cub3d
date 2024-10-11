/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:44 by apernot           #+#    #+#             */
/*   Updated: 2024/10/11 16:53:36 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_vector(t_vector *v1, t_vector *v2)
{
	if (!v1 || !v2)
		return (NULL);
	v1->x = v1->x + v2->x;
	v1->y = v1->y + v2->y;
}

void	sub_vector(t_vector *v1, t_vector *v2)
{
	t_vector *v3;

	if (!v1 || !v2)
		return (NULL);
	v1->x = v1->x - v2->x;
	v1->y = v1->y - v2->y;
}

void	prod_vector(t_vector *v, double scal)
{
	if (!v)
		return (NULL);
	v->x = v->x * scal;
	v->y = v->y * scal;
}

void	rot_vector(t_vector *v, double angle)
{
	if (!v)
		return (NULL);
	v->x = v->x * cos(angle) - v->y * sin(angle);
	v->y = v->x * sin(angle) - v->y * cos(angle);
}


double	dist_vector(t_vector *v)
{
	int	norm;

	if (!v)
		return (0);
	norm = sqrt(v->x * v->x + v->y * v->y);
	return (norm);
}

// RAYCASTING

double	dist(t_vector *start, t_vector *end)
{
	double dist;

	if (!start || !end)
		return (0);
	dist = sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
	return (dist);
}

double corrected_dist(t_vector *start, t_vector *end, double angle)
{
	double	corrected_dist;

	if (!start || !end)
		return (0);
	corrected_dist = dist(start, end) / cos(angle);
	return (corrected_dist);
}

