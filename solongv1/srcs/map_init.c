/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:09:02 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/12 14:54:30 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int map_rows(t_map *game, char *args)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	line = NULL;
	ft_printf("hello\n");
	fd = open(args, O_RDONLY);
	ft_printf("%d\n", fd);
	if (fd == -1)
		error_msg_exit("Error: Where map?\n", game);
	ft_printf("FirstGNL:\n");
	line = get_next_line(fd);
	ft_printf("2\n");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	ft_printf("map_rows:%d\n", i);
	return (i);
}
char	**map_to_str(t_map *game, char *args)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;

	game->map = ft_calloc(game->rows + 1, sizeof(char *));
	fd = open(args, O_RDONLY);
	if (fd == -1)
		error_msg_exit("Error: Where map?\n", game); 
	while (game->rows > i)
	{
		game->map[i] = get_next_line(fd);	
		i++;
	}
	close (fd);
	return (game->map);
}

int	map_init(t_map *game, char *args)
{
	char *map_str;

	map_str = NULL;
	if (!args)
		return (1);
	if (ft_strncmp(args + (ft_strlen(args) - 4), ".ber", 4) != 0)
		error_msg_exit("Bad Map. Must end with .ber\n", game);
	game->rows = map_rows(game, args);
	game->map = map_to_str(game, args);
	if (map_str[0] == '\0')
		error_msg_exit("Error: Empty Map! \n", game);
	free(map_str);
	return (0);
}

	// ft_printf("Map_str is: \n%s\n", map_str);
	// char	*line;
	// char	*temp;
	// char	*result;
	// result = NULL;
	// temp = NULL;
	// free(temp);