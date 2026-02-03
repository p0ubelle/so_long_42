/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:29:43 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/03 22:33:38 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_game *game, t_img *img, int x, int y)
{
	if (game->map[y][x] != '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_floor, x
			* 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_wall, x
			* 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_collect,
			x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_player, x
			* 64, y * 64);
	else if (game->map[y][x] == 'E')
		if (game->exit_visible == 1)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_exit,
				x * 64, y * 64);
}

void	render_map(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			put_image(game, img, x, y);
			x++;
		}
		y++;
	}
}
