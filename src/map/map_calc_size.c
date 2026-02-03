/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:16:48 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/29 13:25:31 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_x_y(t_game *game, char *f_path)
{
	char	c;
	int		fd;
	int		x;
	int		y;
	int		char_count;

	char_count = 0;
	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return ;
	x = 0;
	y = 0;
	while (read(fd, &c, 1) > 0)
	{
		char_count++;
		if (y == 0 && c != '\n')
			x++;
		if (c == '\n')
			y++;
	}
	if ((char_count > 0 && c != '\n') || (y == 0 && x > 0))
		y++;
	close(fd);
	game->map_x = x;
	game->map_y = y;
}
