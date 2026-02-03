/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:32:44 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/03 04:36:22 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	handle_error(char *msg, t_game *game, t_img *img)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (img->img_wall)
		mlx_destroy_image(game->mlx_ptr, img->img_wall);
	if (img->img_floor)
		mlx_destroy_image(game->mlx_ptr, img->img_floor);
	if (img->img_player)
		mlx_destroy_image(game->mlx_ptr, img->img_player);
	if (img->img_collect)
		mlx_destroy_image(game->mlx_ptr, img->img_collect);
	if (img->img_exit)
		mlx_destroy_image(game->mlx_ptr, img->img_exit);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(1);
	return (0);
}
