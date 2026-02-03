/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:29:57 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/03 22:32:47 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_img	img;
	int		valid;

	valid = 0;
	if (argc != 2)
		return (-1);
	ft_memset(&game, 0, sizeof(t_game));
	valid = check_map(&game, argv[1]);
	printf("\nwidth: %d\nheight : %d\ncollectible : %d\nvalid : %d\n\n",
		game.map_x, game.map_y, game.collect_count, valid);

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr || valid != 1)
		return (-1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_x * 64, game.map_y
			* 64, "so_long");

	init_image(&game, &img);
	render_map(&game, &img);
	// mlx_hook(game.win_ptr, 2, 1L << 0, input_begin, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
