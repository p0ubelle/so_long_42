/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 03:37:17 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/04 00:46:57 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(int x, int y, t_game *game)
{
	if (game->map[game->plr_y + y][game->plr_x + x] == '1')
		return ;
	if (game->map[game->plr_y + y][game->plr_x + x] == 'E')
	{
		if (game->collect_count == game->collect_taken)
		{
			ft_putnbr_fd(++game->moves_count, 1);
			write(1, "you win", 7);
			exit(0);
		}
		else
			return ;
	}
	game->plr_x += x;
	game->plr_y += y;
	if (game->map[game->plr_y][game->plr_x] == 'C')
		game->collect_taken++;
	game->map[game->plr_y - y][game->plr_x - x] = '0';
	game->map[game->plr_y][game->plr_x] = 'P';
	ft_putnbr_fd(++game->moves_count, 1);
	write(1, "\n", 1);
	render_map(game, &game->img);
}

int	input_begin(int key_nb, t_game *game)
{
	if (key_nb == 65307)
		exit(0);
	if (key_nb == KEY_A || key_nb == KEY_LEFT)
		player_move(-1, 0, game);
	if (key_nb == KEY_D || key_nb == KEY_RIGHT)
		player_move(1, 0, game);
	if (key_nb == KEY_S || key_nb == KEY_DOWN)
		player_move(0, 1, game);
	if (key_nb == KEY_W || key_nb == KEY_UP)
		player_move(0, -1, game);
	return (0);
}
