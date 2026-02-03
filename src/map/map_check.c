/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:24:16 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/02 18:48:05 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	alloc_map_memory(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->map_y + 1));
	if (!game->map)
		return (0);
	game->map[game->map_y] = NULL;
	return (1);
}

int	check_map(t_game *game, char *f_path)
{
	write(2, "\n", 1);
	get_x_y(game, f_path);
	if (!alloc_map_memory(game))
		return (-1);
	map_tab(game, f_path);
	if (check_extension(f_path) != 1)
		return (write(2, "Error\nExtension fichier invalide", 26 + 7) - 1);
	else if (check_components(game) != 1)
		return (write(2, "Error\nCharacter invalide", 17 + 7), -1);
	else if (game->player_count != 1 || game->exit_count != 1
		|| game->collect_count < 1)
		return (write(2, "Error\nComposants manquant ou en trop", 30 + 7), -1);
	else if (check_rect(game) != 1)
		return (write(2, "Error\nLa map n'est pas rectangulaire", 30 + 7), -1);
	else if (check_wall(game) != 1)
		return (write(2, "Error\nLes murs sont invalides", 23 + 7), -1);
	else if (game->map_x < 3 || game->map_y < 3)
		return (write(2, "Error\nMap trop petite", 15 + 7), -1);
	else if (game->map_x > 60 || game->map_y > 30)
		return (write(2, "Error\nMap trop grande", 15 + 7), -1);
	else if (map_validate(game) != 1)
		return (-1);
	game->exit_visible = 0;
	return (1);
}
