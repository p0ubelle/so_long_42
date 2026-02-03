/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:35:04 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/29 13:35:22 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_rect(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		if ((int)strlen(game->map[y]) != game->map_x)
			return (-1);
		y++;
	}
	return (1);
}
