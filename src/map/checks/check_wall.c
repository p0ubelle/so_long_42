/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:36:08 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/29 13:36:29 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_x)
	{
		if (game->map[0][i] != '1')
			return (-1);
		if (game->map[game->map_y - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->map_x - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}
