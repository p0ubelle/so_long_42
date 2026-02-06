/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:06:09 by rvasseur          #+#    #+#             */
/*   Updated: 2026/02/06 02:09:01 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[j][i] == 'P')
			{
				game->plr_y = j;
				game->plr_x = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**cpy_map(t_game *game)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (game->map_y + 1));
	if (!cpy)
		return (NULL);
	while (i < game->map_y)
	{
		cpy[i] = ft_strdup(game->map[i]);
		if (!cpy[i])
		{
			map_free(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

typedef struct s_check
{
	int	count_collect_validate;
	int	count_exit_validate;
}		t_check;

void	flood_fill(char **new_map, int x, int y, t_check *check)
{
	if (new_map[y][x] == '1' || new_map[y][x] == 'X')
		return ;
	if (new_map[y][x] == 'C')
		check->count_collect_validate++;
	if (new_map[y][x] == 'E')
	{
		check->count_exit_validate++;
		return ;
	}
	new_map[y][x] = 'X';
	flood_fill(new_map, x + 1, y, check);
	flood_fill(new_map, x, y + 1, check);
	flood_fill(new_map, x - 1, y, check);
	flood_fill(new_map, x, y - 1, check);
}

void	map_free(char **new_map)
{
	int	i;

	i = 0;
	while (new_map[i])
	{
		free(new_map[i]);
		i++;
	}
	free(new_map);
}

int	map_validate(t_game *game)
{
	char	**new_map;
	t_check	check;

	check.count_collect_validate = 0;
	check.count_exit_validate = 0;
	find_player(game);
	new_map = cpy_map(game);
	if (!new_map)
		return (-1);
	flood_fill(new_map, game->plr_x, game->plr_y, &check);
	if (game->collect_count != check.count_collect_validate)
	{
		map_free(new_map);
		return (write(2, "Error\n1+ collectibles non accessibles", 31 + 7), -1);
	}
	if (game->exit_count != check.count_exit_validate)
	{
		map_free(new_map);
		return (write(2, "Error\nExit non accessible", 19 + 7), -1);
	}
	map_free(new_map);
	return (1);
}
