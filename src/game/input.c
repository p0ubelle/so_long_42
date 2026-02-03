/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:37:17 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/03 04:23:54 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	input_begin(int key_nb, t_game *game)
{
	if (key_nb == KEY_A || key_nb == KEY_LEFT)
		player_move(-1, 0, game);
	if (key_nb == KEY_D || key_nb == KEY_RIGHT)
		player_move(1, 0, game);
	if (key_nb == KEY_S || key_nb == KEY_DOWN)
		player_move(0, -1, game);
	if (key_nb == KEY_W || key_nb == KEY_UP)
		player_move(0, 1, game);
}

void	player_move(int x, int y, t_game *game)
{
	if (game->map[game->plr_y + y][game->plr_x + x] != '1')
	{
		game->plr_x += x;
		game->plr_y += y;
	}
	if (game->map[game->plr_y][game->plr_x] == 'E')
		write(1, "you win", 7);
	if (game->map[game->plr_y][game->plr_x] == 'C')
		game->collect_taken++;
	if (game->collect_count == game->collect_taken)
		game->exit_visible = 1;
	ft_putnbr_fd(game->moves_count++, 1);
}
