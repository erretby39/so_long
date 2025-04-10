/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:23:55 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/08 18:53:46 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_pos(t_track *pos)
{
	int	i;
	int	j;

	i = 0;
	while (pos->map[i])
	{
		j = 0;
		while (pos->map[i][j])
		{
			if (pos->map[i][j] == 'P')
			{
				pos->x = i;
				pos->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	floodfill(int x, int y, char **map, t_track *game)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		game->e_path = 1;
		return ;
	}
	if (map[x][y] == 'C')
		game->c_valid++;
	map[x][y] = '1';
	floodfill(x + 1, y, map, game);
	floodfill(x - 1, y, map, game);
	floodfill(x, y + 1, map, game);
	floodfill(x, y - 1, map, game);
}

void	last_check(t_track *pos, char *buff2)
{
	if (pos->e_path != 1 || pos->c_count != pos->c_valid)
		ft_error("invalid map\n", buff2, pos);
}

void	map_check(t_track *pos, char *buff2)
{
	char	**map;

	map = NULL;
	pos->c_valid = 0;
	map = ft_split(buff2, '\n');
	p_pos(pos);
	floodfill(pos->x, pos->y, map, pos);
	ft_free(map);
	last_check(pos, buff2);
}
