/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:18:25 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/30 18:39:26 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rm_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

void	map_tab(t_game *game, char *f_path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rm_newline(line);
		game->map[i] = line;
		i++;
	}
	close(fd);
}
