/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:52 by jibanez-          #+#    #+#             */
/*   Updated: 2021/11/29 17:31:32 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_collectable(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.content[i][j] == 'C')
				data->map.collectable++;
			j++;
		}
		i++;
	}
	if (data->map.collectable == FALSE)
		handle_error(data, "NO COLLECTABLES\n", TRUE);
}

static void	map_exit(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.content[i][j] == 'E' && data->map.exit == FALSE)
				data->map.exit = TRUE;
			j++;
		}
		i++;
	}
	if (data->map.exit == FALSE)
		handle_error(data, "NO EXIT\n", TRUE);
}

static void	map_player(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.content[i][j] == 'P' && data->map.player == FALSE)
			{
				data->map.player = TRUE;
				data->map.p_x = j;
				data->map.p_y = i;
			}
			else if (data->map.content[i][j] == 'P' && data->map.player == TRUE)
				handle_error(data, "MORE THAN TWO PLAYERS\n", TRUE);
			j++;
		}
		i++;
	}
	if (data->map.player == FALSE)
		handle_error(data, "NO PLAYER\n", TRUE);
}

static void	map_walled(t_mlx *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	x = data->map.height - 1;
	y = data->map.width;
	print_map(data);
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if ((i == 0 || i == x)
				&& (data->map.content[0][j] != '1'
				|| data->map.content[x][j] != '1'))
				handle_error(data, "WALLS ARE NOT COMPLETE\n", TRUE);
			if ((i > 0 && i < x)
				&& (data->map.content[i][0] != '1'
				|| data->map.content[i][y - 1] != '1'))
				handle_error(data, "WALLS ARE NOT COMPLETE\n", TRUE);
		}
	}
}

void	map_valid(t_mlx *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.content[i][j] != '1'
				&& data->map.content[i][j] != '0'
				&& data->map.content[i][j] != 'P'
				&& data->map.content[i][j] != 'C'
				&& data->map.content[i][j] != 'E')
				handle_error(data, "INVALID SYMBOL\n", TRUE);
		}
	}
	map_walled(data);
	map_player(data);
	map_exit(data);
	map_collectable(data);
}
