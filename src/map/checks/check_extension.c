/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:47:34 by rvasseur          #+#    #+#             */
/*   Updated: 2026/01/30 03:10:05 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_extension(char *filename)
{
	char	*x;

	x = ft_strrchr(filename, '.');
	if (!x)
		return (0);
	if (ft_strcmp(x, ".ber") == 0)
		return (1);
	return (0);
}
