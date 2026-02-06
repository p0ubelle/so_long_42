/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:21:03 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/05 13:41:50 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_image(t_game *game, t_img *img)
{
	img->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/components/wall.xpm", &img->img_width,
			&img->img_height);
	if (img->img_wall == NULL)
		handle_error("Error\nFailed to load wall texture", game, img);
	img->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/components/floor.xpm", &img->img_width,
			&img->img_height);
	if (img->img_floor == NULL)
		handle_error("Error\nFailed to load floor texture", game, img);
	img->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player/idle.xpm", &img->img_width,
			&img->img_height);
	if (img->img_player == NULL)
		handle_error("Error\nFailed to load player texture", game, img);
	img->img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/components/collectible.xpm", &img->img_width,
			&img->img_height);
	if (img->img_collect == NULL)
		handle_error("Error\nFailed to load collect texture", game, img);
	img->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/components/exit.xpm", &img->img_width,
			&img->img_height);
	if (img->img_exit == NULL)
		handle_error("Error\nFailed to load exit texture", game, img);
}
