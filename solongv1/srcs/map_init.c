/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:09:02 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/27 17:01:29 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_rows(t_map *game, char *args)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	line = NULL;
	fd = open(args, O_RDONLY);
	if (fd == -1)
		error_msg_exit("Error: Where map?\n", game);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (line[0] == '\n')
				error_msg_exit("Error: extra line at bottom\n", game);
		}
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

char	**map_to_str(t_map *game, char *args)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	// ft_printf("rows: %d\n", game->rows);
	game->map = (char **)ft_calloc((size_t)game->rows + 1, sizeof(char *));
	if (!game->map)
	{
		free_array(game->map);
		error_msg_exit("Error: calloc failed\n", game);
	}
	fd = open(args, O_RDONLY);
	if (fd == -1)
	{
		free_array(game->map);
		error_msg_exit("Error: Where map?\n", game);
	}
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
	if (!args)
		return (1);
	if ((ft_strlen(args) <= 4) || (args[ft_strlen(args) - 5] == '/')
		|| (ft_strncmp(args + (ft_strlen(args) - 4), ".ber", 4) != 0))
		error_msg_exit("Bad Map. Must end with .ber\n", game);
	game->rows = map_rows(game, args);
	game->map = map_to_str(game, args);
	game->columns = (ft_strlen(game->map[0]) - 1);
	// print_map(game);
	if ((map_parse(game)) == 0)
	{
		free_array(game->map);
		error_msg_exit("Error: Invalid Map! \n", game);
	}
	if (!game->map || !game->map[0])
		error_msg_exit("Error: Empty Map! \n", game);
	// ft_printf("tokens: %d\n", game->tokens);
	// ft_printf("exit: %d\n", game->exit);
	// ft_printf("player: %d\n", game->player);
	return (0);
}

// ft_printf("args len:%d\n", ft_strlen(args));
// ft_printf("Map_str is: \n%s\n", map_str);
// char	*line;
// char	*temp;
// char	*result;
// result = NULL;
// temp = NULL;
// free(temp);