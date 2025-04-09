/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:36:04 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 18:17:16 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void argchek(char *str)
{
    int i;

    i = ft_strlen(str) - 1;

    if(str[i] == 'r' && str[i-1] == 'e'\
        && str[i-2] == 'b' && str[i-3] == '.')
        return ;
    ft_err("Error: this arg not valid\n");
}
void checkers(t_game *game, int ver_line, char *buff2)
{
    map_edge(&game->track, ver_line, buff2);
    map_epc(&game->track, buff2);
    map_check(&game->track, buff2);
    free (buff2);
}

void map_edge(t_track *pos, int ver_line, char *buff2)
{
    int i;
    int j;

    i = 0;
    while (pos->map[i])
    {
        j = 0;
        while(pos->map[i][j])
        {
            if (pos->map[i][j] != '0' && pos->map[i][j] != '1' && \
                pos->map[i][j] != 'E' && pos->map[i][j] != 'P' && pos->map[i][j] != 'C')
                ft_error("Error: only this  {0, 1, E, P, C}\n", buff2, pos);
            if (pos->map[0][j] != '1' || pos->map[ver_line - 1][j] != '1' || \
            pos->map[i][0] != '1' || pos->map[i][ft_strlen(pos->map[i]) - 1] != '1')
                ft_error("Error: map is not valide ;edge", buff2, pos);
            j++;            
        }
        i++;
        if (i < ver_line)
        {
            if(ft_strlen(pos->map[1]) != ft_strlen(pos->map[i]))
                ft_error("Error: diff len of line", buff2, pos);
        }
    }
}

void    map_epc(t_track *pos, char *buff2)
{
    int i;
    int j;
    
    pos->c_count = 0;
    pos->e_count = 0;
    pos->p_count = 0;
    i = 0;
    while(pos->map[i])
    {
        j = 0;
        while(pos->map[i][j])
        {
            if(pos->map[i][j] == 'C')
                pos->c_count++;
            else if(pos->map[i][j] == 'E')
                pos->e_count++;
            else if(pos->map[i][j] == 'P')
                pos->p_count++;
            j++;
        }
        i++;
    }
    if(pos->e_count != 1 || pos->p_count != 1 || \
    pos->c_count == 0)
        ft_error("Error: E=1 , P=1, C>=1", buff2, pos);
}

void    map_parsing(char **av, char *buff, t_game *game, int ver_line)
{
    char *buff2;
    int fd;

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        ft_err("Error: there is no file with this name\n");
    buff2 = NULL;
    buff = get_next_line(fd);
    if (buff == NULL)
        ft_err("empty file\n");
    while(buff)
    {
        if(buff[0] == '\n')
        {
            game->track.map = NULL;
            free(buff);
            ft_error("Error: map is not valid\n", buff2, &game->track);
        }
        buff2 = ft_strjoin(buff2, buff);
        ver_line++;
        free (buff);
        buff = get_next_line(fd);
    }
    game->track.map = ft_split(buff2, '\n');
    checkers(game, ver_line, buff2);
}
