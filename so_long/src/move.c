/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:56:55 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/18 18:00:10 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_mlx *data)
{
	t_coord	coord;

	if (move_is_valid(data, data->map.p_x, data->map.p_y - 1) != -1)
	{
		if (data->map.content[data->map.p_y - 1][data->map.p_x] == 'C')
			data->map.collected += 1;
		previous_tile_space(data, &coord);
		data->map.content[data->map.p_y - 1][data->map.p_x] = 'P';
		calc_coord(data->map.p_x, data->map.p_y - 1, &coord);
		render_asset(data, data->img_p_u_tile.img, coord.x, coord.y);
		data->map.p_y -= 1;
		data->map.steps += 1;
	}
	else
	{
		calc_coord(data->map.p_x, data->map.p_y, &coord);
		render_asset(data, data->img_p_u_tile.img, coord.x, coord.y);
	}
}

void	move_down(t_mlx *data)
{
	t_coord	coord;

	if (move_is_valid(data, data->map.p_x, data->map.p_y + 1) != -1)
	{
		if (data->map.content[data->map.p_y + 1][data->map.p_x] == 'C')
			data->map.collected += 1;
		previous_tile_space(data, &coord);
		data->map.content[data->map.p_y + 1][data->map.p_x] = 'P';
		calc_coord(data->map.p_x, data->map.p_y + 1, &coord);
		render_asset(data, data->img_p_d_tile.img, coord.x, coord.y);
		data->map.p_y += 1;
		data->map.steps += 1;
	}
	else
	{
		calc_coord(data->map.p_x, data->map.p_y, &coord);
		render_asset(data, data->img_p_d_tile.img, coord.x, coord.y);
	}
}

void	move_left(t_mlx *data)
{
	t_coord	coord;

	if (move_is_valid(data, data->map.p_x - 1, data->map.p_y) != -1)
	{
		if (data->map.content[data->map.p_y][data->map.p_x - 1] == 'C')
			data->map.collected += 1;
		previous_tile_space(data, &coord);
		data->map.content[data->map.p_y][data->map.p_x - 1] = 'P';
		calc_coord(data->map.p_x - 1, data->map.p_y, &coord);
		render_asset(data, data->img_p_l_tile.img, coord.x, coord.y);
		data->map.p_x -= 1;
		data->map.steps += 1;
	}
	else
	{
		calc_coord(data->map.p_x, data->map.p_y, &coord);
		render_asset(data, data->img_p_l_tile.img, coord.x, coord.y);
	}
}

void	move_right(t_mlx *data)
{
	t_coord	coord;

	if (move_is_valid(data, data->map.p_x + 1, data->map.p_y) != -1)
	{
		if (data->map.content[data->map.p_y][data->map.p_x + 1] == 'C')
			data->map.collected += 1;
		previous_tile_space(data, &coord);
		data->map.content[data->map.p_y][data->map.p_x + 1] = 'P';
		calc_coord(data->map.p_x + 1, data->map.p_y, &coord);
		render_asset(data, data->img_p_r_tile.img, coord.x, coord.y);
		data->map.p_x += 1;
		data->map.steps += 1;
	}
	else
	{
		calc_coord(data->map.p_x, data->map.p_y, &coord);
		render_asset(data, data->img_p_r_tile.img, coord.x, coord.y);
	}
}

void	move(t_mlx *data, int key)
{
	if (key == XK_Up)
		move_up(data);
	else if (key == XK_Down)
		move_down(data);
	else if (key == XK_Left)
		move_left(data);
	else if (key == XK_Right)
		move_right(data);
	printf("x: %d - y: %d\n""collecables: %d\ncollected: %d\nNum of steps: %d\n",
		data->map.p_x, data->map.p_y, data->map.collectable,
		data->map.collected, data->map.steps);
	print_map(data);
}
