/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:36:53 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/30 18:55:27 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_components(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[j][i] == 'C')
				game->collect_count++;
			if (game->map[j][i] == 'E')
				game->exit_count++;
			if (game->map[j][i] == 'P')
				game->player_count++;
			if (game->map[j][i] != 'C' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'E' && game->map[j][i] != '1'
				&& game->map[j][i] != '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

